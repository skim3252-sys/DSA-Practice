#include <iostream>
#include <vector>
#include <stack>
// 무방향 그래프를 DFS / + stack
using namespace std;
int main(void) {
	int tmp1, tmp2, cnt(0);
	stack<int> st;
	int N, M;
	cin >> N >> M; // M : 간선 개수, N : 정점 개수
	vector<bool> arrive(N+1);
	vector<vector<int>> v(N + 1);
	for (int i = 0; i < M;i++) {
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}

	// 데이터 받아서 간선 정보 정리

	for (int j = 1; j <= N;++j) {
		if (!arrive[j]) {
			++cnt;
			st.push(j);
			arrive[j] = true;
		}
		while (!st.empty()) {
			int tmp_top = st.top();
			st.pop();
			for (auto i : v[tmp_top]) {
				if (!arrive[i]) {
					st.push(i);
					arrive[i] = true;
				}
			}
		}
	}

	cout << cnt;
	return 0;
}