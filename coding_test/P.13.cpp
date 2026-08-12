//백준 4949 — 균형잡힌 세상
//
//여러 줄의 문장이 주어져.각 줄엔 괄호(), [] 말고도 알파벳·공백·기타 문자가 섞여 있어.
//각 문장이 균형잡혔는지 판단 : YES / no 출력
//균형 조건 :
//(는)랑, [는]랑 짝이 맞아야 함
//짝끼리 겹치면 안 됨 : ([)]는 틀림(안쪽[가)보다 먼저 닫혀야 하는데 순서 꼬임)
//괄호 아닌 문자는 무시
//입력 끝 : 마침표.하나만 있는 줄이 나오면 종료
//
//예 :
//
//So when I die(the[first] I will see in(heaven) is a score list ? → 짝 안 맞음 → no
//	[first in](first out).→ yes
//	([)] → no(순서 꼬임)

#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	map<char, char> m;
	m[')'] = '(';
	m['>'] = '<';
	m[']'] = '[';
	char cn;
	string tmp;
	while (getline(cin, tmp)) {
		if (tmp == ".") break;
		stack<char> arr;
		bool dec = true;

		for (int i = 0; i < tmp.length();i++) {
			if (tmp[i] == '(' || tmp[i] == '<' || tmp[i] == '[') {
				arr.push(tmp[i]);
			}
			else if (tmp[i] == ')' || tmp[i] == '>' || tmp[i] == ']') {
				cn = tmp[i];
				if (!(arr.empty())) {
					if (arr.top() == m[cn]) {
						arr.pop();
					}
					else dec = false;
				}
				else dec = false;
			}
			else continue;
		}
		if (dec) dec = arr.empty();
			(dec) ? (cout << "Yes\n") : (cout << "No\n");
	}
	return 0;
}
// 배열적 요소는 empty() 확인 필수 
// getline(cin,[string]) 