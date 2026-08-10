//P6 중복 뭉치 해결까지

//N개의 정수가 주어져(3 ≤ N ≤ 5, 000)
//서로 다른 세 수를 골라서 합이 0이 되는 경우의 수를 구해라
//값은 음수도 양수도 가능

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N; cin >> N;
	int right, left;
	int tmp;
	long long cnt(0);
	vector<int> arr;
	for (int i = 0; i < N;++i) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	int asdf(0);
	int fdsa(0);
	for (int i = 0; i < N - 2;++i) {
		left = i + 1; right = N - 1;
		while (right > left) {
			if (0 == arr[i] + arr[right] + arr[left]) {
				asdf = upper_bound(arr.begin()+left, arr.begin()+right+1, arr[left]) -
					lower_bound(arr.begin() + left, arr.begin()+right + 1, arr[left]);
				fdsa = upper_bound(arr.begin() + left, arr.begin()+right + 1, arr[right]) -
					lower_bound(arr.begin() + left, arr.begin()+ right + 1, arr[right]);
				if (arr[right] == arr[left]) {
					tmp = right - left;
					cnt += (tmp + 1) * tmp / 2;
					left += asdf;
					right -= fdsa;
					break;
				}
				cnt += asdf * fdsa;
				left += asdf;
				right -= fdsa;
			}
			else if (0 > arr[i] + arr[right] + arr[left]) {
				--right;
			}
			else ++left;
		}
	}
	cout << cnt;

	return 0;
}
