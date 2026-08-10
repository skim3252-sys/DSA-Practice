//백준 3151 — 합이 0
//
//N개의 정수가 주어져(3 ≤ N ≤ 5, 000)
//서로 다른 세 수를 골라서 합이 0이 되는 경우의 수를 구해라
//값은 음수도 양수도 가능

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> arr;
	int N; cin >> N;
	int tmp, sum(0);
	long long cnt(0);
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; ++i) {
		int right(N - 1), left(i + 1);

		while (left < right) {
			cout << "i : " << i << '\t';
			printf("left : %d , right : %d, sum : %d \n", left, right,
				arr[i] + arr[left] + arr[right]);
			
			if (0 == arr[i] + arr[left] + arr[right]) {
				++cnt;
				// 중복 뭉치 해결코자 하였지만 이분 탐색 없이 까다로움(실패)
				if (left != right) {
					if (arr[left] == arr[left + 1]) {
						++left; continue;
					}
					else if (arr[right] == arr[right - 1]) {
						--right; continue;
					}
				}
				++left; --right;

			}
			else if (0 > arr[i] + arr[left] + arr[right]) {
				++left;
			}
			else --right;
		}
	}

	cout << "cnt : " << cnt;

	return 0;
}

