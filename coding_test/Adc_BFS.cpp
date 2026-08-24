#include <iostream>
#include <vector>
#include <queue>
// 익은 토마토 문제 day 기준 시간복잡도 day * N * M
using namespace std;

int main(void) {
	int N, M; cin >> N >> M;
	int cnt(0);
	int T_cnt(0);
	int day(0);
	bool changed(true);
	vector<vector<int>> tomato(N, vector<int>(M, 0)); // tomato 1, 0, -1 상태
	vector<vector<bool>> arrive(N, vector<bool>(M, false)); // 기록, 사용 안해도 됨
	queue<pair<int, int>> Q; // 좌표
	//배열 넣고 -1 개수 파악
	for (int i = 0; i < N;++i) {
		for (int j = 0; j < M;++j) {
			cin >> tomato[i][j];
			if (tomato[i][j] == -1) { cnt++; }
			if (tomato[i][j] == 1) { T_cnt++; }
		}
	}
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	//익은 토마토 개수가 토마토 개수 이상일 때 까지
	while (T_cnt < N * M - cnt) {
		T_cnt = 0;
		day++;
		changed = false;
		// 익은 토마토 개수 파악
		for (int i = 0; i < N;++i) {
			for (int j = 0; j < M;++j) {
				if (tomato[i][j] == 1) {
					Q.push({ i,j });
					//arrive[i][j] = true;
					++T_cnt;
					cout << T_cnt << endl;
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
					if (tomato[nx][ny] ==0) {
						tomato[nx][ny] = 1;
						++T_cnt;
						changed = true;
					}
				}
			}
		}

		//for (int i = 0; i < N;++i) {
		//	for (int j = 0; j < M;++j) {
		//		cout << tomato[i][j];
		//	}
		//	cout << endl;
		//}
		if (!changed) { break; }
	}

	changed ? cout << day : cout << -1;
	return 0;
}