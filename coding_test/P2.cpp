#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr1;
	for (int i = 0; i < n; ++i) {
		int tmp(0);
		cin >> tmp;
		arr1.push_back(tmp);
	}
	sort(arr1.begin(), arr1.end());
	arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());

	for (auto i : arr1) cout << i << " ";
	return 0;
}
/*

암기 할 것 unique : 중복 된 값을 뒤로 보내고 중복되지 않는 주소 값 뒤(end())
sort(arr1.begin(), arr1.end());
arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());

=> 중복 X 값들만 남기는 형태 / unique : 연속된 중복만 제거함

*/