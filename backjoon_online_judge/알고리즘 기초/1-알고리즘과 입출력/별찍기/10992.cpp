//10992 별찍기-17
/*

4
   *
  * *
 *   *
*******

 */
#include <iostream>
#include <cstdio>

using namespace std;

int star;
int max_bl;
int star_num;
int mid;
int flag =1;

void input() {
	scanf("%d", &star);
	max_bl = star*2 -1;
	mid = max_bl / 2 + 1;
}
void solve() {
	for (int i = 1; i <= star; i++) {
		//�� �ٿ� ��� ���� ����
		if (i == 1) star_num = 1;
		else star_num = 2;
		//�����
		for (int j = 1; j <= max_bl; j++) {
			if (star_num == 0) break;
			if ( j >= mid ) {
				if (mid == 1) {
					printf("*");
				}
				else if ((j==mid)||(j==max_bl-mid+1)) {
					printf("*");
					star_num--;
				}
				else printf(" ");
			}
			else printf(" ");
		}
		mid--;
		flag = 1;
		printf("\n");
	}
}
int main() {
	input();
	solve();
}
