//백준 2018 — 수들의 합 5
//
//자연수 N이 주어져(1 ≤ N ≤ 10, 000, 000)
//연속된 자연수들의 합으로 N을 만드는 경우의 수를 구해라
//자기 자신(N 하나)도 한 경우로 친다
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int right(1), left(1), sum(1);
	int N; cin >> N;
	int cnt(0);
	while (right <= N) {
		//for (int i = left; i < right; ++i) {
		//	sum += i;
		//}
		printf("right : %d , left : %d , sum : %d \n", right, left , sum);

		if (sum < N) {
			++right;
			sum += right;
		}
		else if (sum == N || sum > N) {
			if (sum == N) ++cnt;
			sum -= left;
			++left;
			
		}
	}
	cout << cnt;
	return 0;
}