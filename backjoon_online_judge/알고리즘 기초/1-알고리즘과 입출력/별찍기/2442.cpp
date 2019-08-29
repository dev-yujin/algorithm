// 2442 별찍기 - 5
/*

4
   *
  ***
 *****
*******

 */
#include <iostream>
#include <cstdio>

using namespace std;

int star;
int max_bl;
int star_num;
int mid;

void input() {
	scanf("%d", &star);
	max_bl = star * 2 - 1;
	mid = max_bl / 2 +1;
}
void solve() {
	for (int i = 1; i <= star; i++) {
		star_num = i * 2 - 1;
		for (int j = 1; j <= max_bl; j++) {
			if ((j >= mid) && (star_num != 0)) {
				printf("*");
				--star_num;
			}
			else printf(" ");
			if (star_num == 0) break;
		}
		printf("\n");
		mid--;
	}
}
int main() {
	input();
	solve();
}
