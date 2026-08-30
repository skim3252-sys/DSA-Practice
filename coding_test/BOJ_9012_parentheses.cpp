#include <iostream>
#include <vector>
#include <stack>
#include <string>

// stack 비울때는 stack<char>().swap(s); 또는 초기화
using namespace std;
int main(void) {
	
	string tmp;
	int T(0); cin >> T;
	while(T--) {
		stack<char> arr; 
		bool dec = true;
		cin >> tmp;		 
		for (int i = 0; i < tmp.length(); ++i) {
			if (tmp[i] == '(') {
				arr.push('(');
			}
			else if (tmp[i] == ')') {

				if (arr.empty()) {
					dec = false;
					break;
				}
				arr.pop();

			}
			else continue;
		}

		if(dec) dec = arr.empty();
		(dec) ? (cout << "Yes\n") : (cout << "No\n");
	}
	return 0;
}
