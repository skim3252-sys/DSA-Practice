//백준 1920 — 수 찾기 변경
//
//N개의 정수 배열(N ≤ 100, 000)
//M개의 질문.각 질문마다 "이 수가 배열에 있어? 있으면 1, 없으면 0 출력" (M ≤ 100, 000)
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(void) {
	int left, mid, right, target;
	int tmp; int N; cout << "배열 수 : "; cin >> N;
	bool dec = false;
	vector<int> arr;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; ++i) {
		tmp = rand();
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		left = 0;  right = N - 1;
		cout << "target: "; cin >> target;
		dec = false;
		while (right >= left) {
			mid = (left + right) / 2;
			//mid = left + (right + left)/2  오버플로 방지
			//long long mid 로 설정도 가능
			if (arr[mid] > target) {
				right = mid - 1;
			}
			else if (arr[mid] < target) {
				left = mid + 1;
			}
			else {
				dec = true;
				break;
			}
		}
		cout << (dec ? 1 : 0) << '\n';
	}
	return 0;
}