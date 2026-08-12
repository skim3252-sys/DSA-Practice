#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	
	int N; cin >> N;
	queue<int> v;
	//queue<int> vv;
	for (int i = 1; i <= N; ++i) {
		v.push(i);
	}
	while (v.size()> 1) {
		v.pop();
		v.push(v.front());
		v.pop();
		//vv = v;
		//while(!vv.empty()) {
		//	cout << vv.front() << " ";
		//	vv.pop();
		//}
		//cout << '\n';
	}
	cout << v.front();
	return 0;
}
