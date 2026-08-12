#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> q;
	string cmd;
	int N;cin >> N;
	while (N--) {
		
		cin >> cmd;
		if (cmd == "push_front") {
			int x; cin >> x;
			q.push_front(x);
		}
		else if (cmd == "push_back") {
			int x; cin >> x;
			q.push_back(x);
		}
		else if (cmd == "pop_front") {
			if (q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << '\n';
			q.pop_front();
		}
		else if (cmd == "pop_back") {
			if (q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << q.back() << '\n';
			q.pop_back();
		}
		else if (cmd == "size") {
			cout << q.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << q.empty() << '\n';
		}
		else if (cmd == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << '\n';
		}
		else if (cmd == "back") {
			if (q.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << q.back() << '\n';
		}
		else continue;
	}
	return 0;
}
//enum 은 정수에 이름 붙이기, switch는 정수나 문자만 가능 