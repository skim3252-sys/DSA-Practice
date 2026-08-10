#include <iostream>
#include <vector>

using namespace std;

// N 개의 수의 최댓값과 번수 찾기
int main(void) {
	vector<int> arr1;
	int n, big=0, count(0),tmp1(0); // 기준 변수 초기화를 배열 첫 값으로 
	int tmp;
	cin >> n;
	for (int i = 0; i < n ;i++) {
		cin >> tmp;
		arr1.push_back(tmp); 
	}
	for (auto i : arr1) {
		++count;
		if (i > big) { big = i; tmp1 = count; }
	}
	cout << big << " " << tmp1;

	return 0;
}

