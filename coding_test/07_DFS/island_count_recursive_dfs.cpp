#include <iostream>
#include <vector>
#include <stack>
//섬 개수 찾기 +  재귀 함수 이용 DFS
using namespace std;
int N, M; 
stack<int> st; // 재귀 DFS -> 이미 함수 호출 스택 사용 
vector<vector<int>> ground;
vector<vector<bool>> arrive;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
void dfs(int x, int y) {
	//if(!arrive[x][y]){}
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny < M && ny >= 0) {
			if (!arrive[nx][ny] && ground[nx][ny] == 1) {
				arrive[nx][ny] = true;
				dfs(nx, ny);
			}
		}

	}
}
int main(void) {
	cin >> N >> M;
	ground.resize(N, vector<int>(M, 0));
	arrive.resize(N, vector<bool>(M, false));
	int cnt(0); 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M;j++) {
			cin >> ground[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M;j++) {
			if (arrive[i][j] == false && ground[i][j] == 1) {
				arrive[i][j] = true;
				dfs(i, j);
				++cnt;
			}
		}
	}
	cout << cnt;
	return 0;
}