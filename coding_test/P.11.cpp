#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int N; cin >> N;
	int Min_left(0), Min_right(N - 1), tmp;
	long long Min_sum = 4000000000;
	vector<int> arr;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	int  target;
	for (int i = 0; i < N - 1;++i) {
		target = -arr[i];
		auto pos = lower_bound(arr.begin(), arr.end(), target);
		int p = pos - arr.begin();
		for (auto point : { p, p - 1 }) {
			if (point >= N || point < 0 || point == i) continue;
			if (abs(arr[point] + arr[i]) <= Min_sum) {
				Min_sum = abs(arr[point] + arr[i]);
				Min_left = min(point, i); Min_right = max(point, i);
			}
			else continue;
		}
		//&arr[0] 와 iterator은 다름 ->iterator 과 pointer 차이 존재
		//이분 탐색 stl 사용 시 end() 반환, 크러쉬 명심
	}
	cout << arr[Min_left]<< " " << arr[Min_right];
	return 0;
}
//int main(void) {
//
//	int N; cin >> N;
//	vector<int> arr;
//	int tmp,right, left;
//	long long sum;
//	for (int i = 0; i < N; i++) {
//		cin >> tmp;
//		arr.push_back(tmp);
//	 }
//	
//	right = N-1; left = 0;
//	int M_right(right), M_left(left);
//	sum = abs(arr[right] + arr[left]);
//	while (right > left) {
//		
//		if (sum > abs(arr[right] + arr[left])) {
//			sum = abs(arr[right] + arr[left]);
//			M_right = right;
//			M_left = left;
//		}
//		if (arr[right] + arr[left] > 0) {
//			--right;
//		}
//		else if (arr[right] + arr[left] < 0) {
//			++left;
//		}
//		else {
//			break;
//		}
//	}
//	cout << arr[M_left] << " " << arr[M_right];
//	return 0;
//}