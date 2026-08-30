#include <iostream>
#include <vector>
// 무방향 그래프를 DFS  +  함수 재귀 스택
using namespace std;
int N, M;
vector<vector<int>> v;
vector<bool> arrive;

void dfs(int x) {
	arrive[x] = true;
	for (auto i : v[x]) {
		if (arrive[i] != true) {
	
			dfs(i);
		}
	}
}

int main(void) {
	int tmp1, tmp2, cnt(0);
	cin >> N >> M; // M : 간선 개수, N : 정점 개수
	v.resize(N + 1);
	arrive.resize(N + 1);
	for (int i = 0; i < M;i++) {
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}

	// 데이터 받아서 간선 정보 정리

	for (int j = 1; j <= N;++j) {
		if (!arrive[j]) {
			++cnt;
			dfs(j);
		}
	}

	cout << cnt;
	return 0;
}