#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int dx[4] = { -1, 1,0,0 };
	int dy[4] = { 0, 0,-1,1 };
	int x(0), y(0);
	string str;
	int row, colunm, cnt(0);
	cin >> row >> colunm;
	queue<pair<int, int>> q;
	vector<vector<pair<int, int>>>
		check(row, vector < pair<int, int>>(colunm, { 0,0 }));
	// 
	//vector<vector<int>> dist(row, vector<int>(colunm,0));
	cin.ignore();
	while (getline(cin, str)) {
		for (int i = 0; i < colunm;++i) {
			check[cnt][i].first = (str[i] - '0'); // 값 1, 0 길 or 벽
			//check[cnt][i].second = 0; // 방문 기록 및 거리
		}
		cnt++;
	}
	q.push({ 0,0 });
	check[0][0].second = 1;
	//dist[0][0] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i < 4; i++) {
			int Nx = x + dx[i];
			int Ny = y + dy[i];
			if (Nx >= 0 && Nx < row && Ny >= 0 && Ny < colunm) {
				if (check[Nx][Ny].second == 0) {
					if (check[Nx][Ny].first == 1) {
						q.push({ Nx, Ny });
						check[Nx][Ny].second = check[x][y].second + 1;
					}
				}
			}
		}
		q.pop();
	}
	cout << check[row-1][colunm-1].second;

	return 0;
}

// 배열 실제 인덱스 범위 유의할것
// while (!q.empty()) 로 종료
// 거리 = dist[x][y] + 1 로 상대 cnt 로써 사용할 것
//거리 == 0 일때 방문 X로 인식해서 vector<vetor<pair<int,int>>> 2개의 변수로만 확인