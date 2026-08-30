#include <iostream>
#include <vector>
#include <queue>
// 익은 토마토 문제 : 멀티소스 BFS 로 시간 복잡도 N * M
using namespace std;

int main(void) {
	int N, M; cin >> N >> M;
	bool imp(false);
	vector<vector<int>> tomato(N, vector<int>(M, 0)); // tomato 1, 0, -1 상태
	queue<pair<int, int>> Q; // 좌표
	//배열 넣고 -1 개수 파악
	for (int i = 0; i < N;++i) {
		for (int j = 0; j < M;++j) {
			cin >> tomato[i][j];
		}
	}
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	//익은 토마토 개수가 토마토 개수 이상일 때 까지
		// 익은 토마토 개수 파악
	for (int i = 0; i < N;++i) {
		for (int j = 0; j < M;++j) {
			if (tomato[i][j] == 1) {
				Q.push({ i,j });
			}
		}
	}
	// 익은 토마토와 연결된 박스 내 토마토 상태 변환
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				//arrive[nx][ny] = true;
				if (tomato[nx][ny] == 0) {
					tomato[nx][ny] = tomato[x][y] + 1;
					Q.push({ nx,ny });
				}
			}
		}
	}
	int max_day(0);
	for (int i = 0; i < N && !imp;++i) {
		for (int j = 0; j < M;++j) {
			if (tomato[i][j] == 0) {
				imp = true; break;
			}
			max_day = max(max_day, tomato[i][j]);
		}
	}
	(imp) ? cout << -1 : cout << max_day - 1;
	return 0;
}