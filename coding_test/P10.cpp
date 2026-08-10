//백준 2805 — 나무 자르기
//
//나무 N그루가 각각 높이를 가지고 있어(N ≤ 1, 000, 000)
//절단기 높이 H를 설정하면, H보다 높은 나무들은 H 위쪽 부분이 잘려. (예: 높이 20 나무를 H = 15로 자르면 5만큼 가져감. 15 이하 나무는 안 잘림)
//적어도 M미터의 나무를 집에 가져가려고 해
//M미터를 확보할 수 있는 절단기 높이 H의 최댓값을 구해라(나무를 필요 이상으로 안 베려고 최대한 높게 설정)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> arr;
	int right, left, mid;
	int tmp;
	int N; cin >> N;
	int target; cin >> target;
	long long sum(0);
	int Max(0), answer;
	int Min_sum;
	bool cnt = true;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
		if (Max < tmp) Max = tmp;		
	}
	right = Max; left = 0;
	while (right >= left) {
		sum = 0;
		mid = (right + left) / 2;

		for (auto i : arr) {
			if (i > mid) {
				sum += i - mid;
				if (cnt) {
					Min_sum = sum;
					cnt = false;
				}
			}
		}
		if (target <= sum) {
			left = mid + 1;
			answer = mid;
			Min_sum = sum;
		}

		else {
			right = mid - 1;
		}
	}
	cout << " mid : " << answer << endl;
	cout << "Min_sum : " << Min_sum;
	return 0;
}