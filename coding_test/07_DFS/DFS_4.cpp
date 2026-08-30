//N개의 정점과 M개의 무방향 간선이 주어진다.
//각 연결 요소의 크기를 오름차순으로 출력하라. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<bool> arrive;
int dfs(int x) {
	int cnt = 1;
	arrive[x] = true;
	for (auto i : v[x]) {
		if (arrive[i] != true) {
			cnt += dfs(i);
		}
	}
	return cnt;
}


int main(void) {
	vector <int> result;
	int N, M; cin >> N >> M; // M : 간선 개수, N : 정점 개수
	v.resize(N + 1);
	arrive.resize(N + 1, false);
	for (int i = 0; i < M; ++i) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}
	for(int j = 1; j <= N; ++j) {
		if(!arrive[j]) {
			int size_ = dfs(j);
			result.push_back(size_);
		}
	}

	sort(result.begin(), result.end());
	for (const auto& r : result) {
		cout << r << " ";
	}
	return 0;
}
