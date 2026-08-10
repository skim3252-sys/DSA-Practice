#include <vector>
#include <algorithm>
#include <iostream>	
using namespace std;
// 배열에서 두 수의 합이 target에 일치하는 조합개수
int main(void) {
	int N; cin >> N;
	int tg; cin >> tg;
	int alpha;
	//vector<int> arr1[N];
	vector<int> arr1;
	for (int i = 0; i < N;++i) {
		cin >> alpha;
		arr1.push_back(alpha);
	}
	sort(arr1.begin(), arr1.end());
	int rs = N - 1;
	int ls(0);
	int cnt(0);
	while (ls < rs) {
		if (arr1[ls] + arr1[rs] == tg) {
			++cnt;
			++ls; --rs;
		}
		else if (arr1[ls] + arr1[rs] > tg) {
			--rs;
		}
		else ++ls;

	}

	cout << cnt;

	return 0;
}

// vector<int>iterator rs, ls 로 begin(), end()에 엮어도 되지만 인덱스가 더 간편