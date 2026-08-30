#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	stack<int> arr;
	int K; cin >> K;
	int tmp, sum(0); 
	for (int i = 0; i < K; ++i) {
		cin >> tmp;
		if (tmp == 0) {
			if (!arr.empty()) {
				arr.pop();
			}
			continue;
		}
		arr.push(tmp);
	}
	while(!arr.empty()) {
		sum += arr.top();
		arr.pop();
	}
	cout << sum;
	return 0;
}

//전체 훑기 while(!empty) 이용