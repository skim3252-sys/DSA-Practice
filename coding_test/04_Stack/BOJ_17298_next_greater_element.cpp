//백준 17298 — 오큰수
//
//크기 N인 수열이 있어(N ≤ 1, 000, 000)
//각 원소 A[i]에 대해 * *오큰수 NGE(i) * *를 구해라
//오큰수 = A[i]보다 오른쪽에 있으면서, A[i]보다 큰 수 중 가장 왼쪽(제일 먼저 나오는) 수
//그런 수가 없으면 - 1
//
//예: [3, 5, 2, 7]
//
//3의 오큰수 → 오른쪽에서 3보다 큰 첫 수 = 5
//5의 오큰수 → 오른쪽에서 5보다 큰 첫 수 = 7
//2의 오큰수 → 7
//7의 오큰수 → 오른쪽에 더 큰 거 없음 → - 1
//답 : 5 7 7 - 1

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
//스택에 index 저장 후 조건 충족 시 연결
int main(void) {
	//stack<int> arr;
	vector<int> v;
	int N; cin >> N;
	vector<int> N_v(N, -1);
	stack<int> tmp1;
	int tmp,sum(0);
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < N; ++i) {
		if (tmp1.empty()) {
			//cout << '1\n';
			tmp1.push(i);
			continue;
		}
		else {
			while (!tmp1.empty() && v[tmp1.top()] < v[i]) {
				sum += v[i];
				//cout << sum << endl;
				N_v[tmp1.top()] = v[i];
				tmp1.pop();
			}
			tmp1.push(i);
		}
	}
	while (!tmp1.empty()) {
		sum += -1;
		tmp1.pop();
	}
	for (auto i : N_v) {
		cout << i << " ";
	}
	cout << "sum : " << sum;
	return 0;
}

// 2개의 stack 에 굳이 index와 값을 넣어서 따로 처리 X
	//for (int i = 0; i < N; ++i){
	//	cin >> tmp;
	//	v.push_back(tmp);
	//}
	//for (int i = 0; i < N; ++i) {
	//	if (arr.empty()) {
	//		//cout << '1\n';
	//		arr.push(v[i]);
	//		tmp1.push(i);
	//		continue;
	//	}
	//	else {
	//		while (!arr.empty() && arr.top() < v[i]) {
	//			sum += v[i];
	//			//cout << sum << endl;
	//			N_v[tmp1.top()] = v[i];
	//			arr.pop();
	//			tmp1.pop();
	//		}
	//		arr.push(v[i]);
	//		tmp1.push(i);
	//	}
	//}
	//while (!arr.empty()) {
	//	sum += -1;
	//	arr.pop();
	//}