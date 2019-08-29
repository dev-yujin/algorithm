//2446 별찍기-9
/*

5
*********
 *******
  *****
   ***
    *
   ***
  *****
 *******
*********

 */

#include <iostream>
#include <cstdio>

using namespace std;

int star;
int max_bl;
int star_num;
int bl_num;
int mid;

void input() {
	scanf("%d", &star);
	max_bl = star * 2 - 1;
	mid = 1;
}
void solve() {
	for (int k = star; k >= 1; k--) {
		star_num = k * 2 - 1;
		for (int j = 1; j <= max_bl; j++) {
			if ((j >= mid) && (0 != star_num)) {
				printf("*");
				star_num--;
			}
			else printf(" ");
			if (star_num == 0) break;
		}
		printf("\n");
		mid++;
	}
	mid -= 2;
	for (int i = 2; i <= star; i++) {
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