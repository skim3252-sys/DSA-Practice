//백준 2470 — 두 용액
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int right, left;
	long long sum(0);
	int min_right, min_left;
	int N; cin >> N;
	vector<int> arr;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	min_left = left = 0;
	min_right = right = N - 1;
	sum = abs( arr[right] + arr[left]);
	while (right > left) {
		cout << min_right << " " << min_left << " " << right << " " << left 
			<< " " << sum << '\n';
		if (sum >= abs(arr[right] + arr[left])) {
			sum = abs(arr[right] + arr[left]);
			min_right = right;
			min_left = left;
			if (sum == 0) break;
		}
		if ((arr[right] + arr[left]) > 0) --right;
		//else if ((arr[right] + arr[left]) < 0) ++left;
		else ++left; // 이러면 위에 케이스 분리 없어도 안전하게 0 무한루프 X
	}
	cout << arr[min_left] << " : " << arr[min_right];
	return 0;
}