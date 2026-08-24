#include <iostream>
#include <vector>
#include <queue>
// BFS 영역 개수 밑 크기 확인 예제
using namespace std;
int main(void) {
	int N, M, cnt(0); cin >> N >> M;
	int max_area(0);
	vector<vector<pair<int, int>>> v(N, vector<pair<int, int>>(M, { 0, 0 }));

	for (int i = 0; i < N;++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j].first;
		}
	}
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };

	queue<pair<int, int>> Q;
	for (int i = 0; i < N;++i) {
		for (int j = 0; j < M; ++j) {
			int area(0);
			if (v[i][j].second == 0 && v[i][j].first == 1) {
				Q.push({ i,j });
				v[i][j].second = 1;
				cnt++;
				printf("%d, %d \n", i, j);
			}

			while (!Q.empty()) {
				int x = Q.front().first;
				int y = Q.front().second;
				Q.pop(); // x,y에 넣고 pop();
				area++;
				for (int k = 0; k < 4;++k) {
					int Nx = x + dx[k];
					int Ny = y + dy[k];
					if (Nx >= 0 && Nx < N && Ny >= 0 && Ny < M) {
						if (v[Nx][Ny].second == 0 && v[Nx][Ny].first == 1) {
							v[Nx][Ny].second = 1;
							Q.push({ Nx, Ny });
						}
					}
				}
			}
			max_area = max(max_area, area);

		}
	}

	cout << "그림 개수 : " << cnt << " / 최대 크기 : " << max_area;
	return 0;
}