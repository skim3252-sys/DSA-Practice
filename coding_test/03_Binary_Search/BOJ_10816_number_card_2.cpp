//백준 10816 — 숫자 카드 2
//
//상근이가 가진 숫자 카드 N개(N ≤ 500, 000)
//질문 M개(M ≤ 500, 000).각 질문마다 "그 숫자 카드를 몇 개 갖고 있냐" 출력
//카드 숫자 범위 : -1000만 ~1000만
//이진 탐색 . STL 사용해보기~
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
int main(void) {
	int N; cin >> N;
	vector<int> arr;
	int tmp, count;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	int M,target; cin >> M; // -1000만 < target < 1000만
	for (int j = 0; j < M; ++j) {
		cin >> target;
		count = upper_bound(arr.begin(), arr.end(), target)
			- lower_bound(arr.begin(), arr.end(), target);
		cout << count <<'\n';
	}


	return 0;
}