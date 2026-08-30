#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int row, column; cin >> row >> column;
	vector<vector<pair<int, int>>> v(row, vector<pair<int, int>>(column, { 0, 0 })); // 땅/바다  , 방문 기록
	queue<pair<int, int>> q;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int x(0), y(0), cnt(0);
	//받아야됨
	string str;
	
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0;j < column; j++) {
			v[i][j].first = str[j]-'0';
		}
	}
	//for (int i = 0; i < row; i++) {
	////	for (int j = 0;j < column; j++) {
	////		cout << v[i][j].first;
	////	}
	////	cout << '\n';
	////}

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			if (v[i][j].second == 1) { continue; } //	방문기록 확인
			if (v[i][j].first == 0) { continue; } //	땅 확인

			q.push({i,j});	//큐 넣고 x,y 갱신
			v[i][j].second = 1;	 //방문 기록 넣기

			while (!q.empty()) {
				x = q.front().first;
				y = q.front().second;
				q.pop();
				for (int k = 0; k < 4;++k) {
					int Nx = x + dx[k];
					int Ny = y + dy[k];
					if (Nx >= 0 && Nx < row && Ny>=0 && Ny < column) {
						if (v[Nx][Ny].first == 1) { // 땅인지
							if (v[Nx][Ny].second == 1) { continue; } // 한 BFS에서 방문기록 
							q.push({ Nx , Ny });
							v[Nx][Ny].second = 1;
						}
					}
				}
			}
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}