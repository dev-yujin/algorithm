//10799 쇠막대기 (백준 솔루션)

#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string str;
stack<int> s;
int star; //레이저의 갯수
int piece = 0;
int len;

void input() {
	cin >> str;
	len = str.length();
}
void solve() {
	
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else { //인덱스가 하나차이나면 레이저임 /앞에것 까지 잘라서 답에 더함
			if (s.top() == i - 1) {
				s.pop();
				piece += s.size();
			}
			else {
				s.pop();
				piece++;
			}
		}
	}
}

void output() {
	printf("%d\n", piece);
}

int main() {
	input();
	solve();
	output();
}