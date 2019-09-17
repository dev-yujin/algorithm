//9012 괄호

#include <iostream>
#include <stack>
#include <string>
#include <stack>

using namespace std;

int row;
string str;
stack<char> s;

int isStr(string str) {
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else { // ) 이면
			if (s.empty()) {
				return 0;
			}
			else s.pop();
		}
	}

	if (s.empty()) return 1;
	else return 0;
}


void input() {
	cin >> row;
	//받을 문자열 갯수
}

void solve() {
	for (int i = 0; i < row; i++) {
		cin >> str;
		if (isStr(str) == 1) {
			cout << "YES\n";
		}
		else cout << "NO\n";

		//stack clear
		while (!s.empty()) { 
			s.pop();
		}
	}
}

int main() {
	input();
	solve();

}
