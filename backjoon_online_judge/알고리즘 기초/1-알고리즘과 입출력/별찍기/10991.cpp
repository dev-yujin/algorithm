//10991 별찍기 - 16
/*
3
  *
 * *
* * *

5
    *
   * *
  * * *
 * * * *
* * * * *

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
		star_num = i;
		for (int j = 1; j <= max_bl; j++) {
			if (star_num == 0) break;
			if ( j >= mid ) {
				if (flag == 1) {
					printf("*");
					star_num--;
					flag = 0;
				}
				else if (flag == 0) {
					printf(" ");
					flag = 1;
				}
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