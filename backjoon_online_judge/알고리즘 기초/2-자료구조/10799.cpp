//10799  쇠막대기  (시간초과)
#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> s;
int star; // 레이저의 갯수
int piece = 0;
int len;

void input() {
	cin >> str;
	len = str.length();
}
void solve() {
	
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			if (str[i + 1] == ')') {
				//레이저이면 *을 push
				s.push('*');
				i++;
			}
			else s.push(str[i]); //아니면 (을 push
		}
		else { // ')' 일 경우 -> 막대의 끝임
			while (s.top() != '(') {
				if (s.top() == '*') star++;  //레이저수
				s.pop();
			}
			s.pop(); // '('을 스택에서 제거
			// '('을 만남
			piece += (star + 1); //조각의 수를 계산 할 것임
								 
			for (int i = 0; i < star; i++) s.push('*'); //레이저를 집어 넣음
			star = 0;
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
