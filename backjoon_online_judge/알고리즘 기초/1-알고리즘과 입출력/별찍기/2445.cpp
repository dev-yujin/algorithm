//2445  별찍기- 8
/*

4
*      *
**    **
***  ***
********
***  ***
**    **
*      *

 */

#include <iostream>
#include <cstdio>

using namespace std;

int star;
int max_bl;
int star_num;

void input() {
	scanf("%d", &star);
	max_bl = star * 2 ;
	star_num = 0;
}
void solve() {
	for (int i = 1; i <= star; i++) {
		star_num += 2;
		for (int j = 1; j <= max_bl; j++) {
			if ((j <= star_num / 2) || (j > (max_bl - star_num / 2)))
				printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	star_num = max_bl;
	for (int i = 1; i <= star-1; i++) {
		star_num -= 2;
		for (int j = 1; j <= max_bl; j++) {
			if ((j <= star_num / 2) || (j > (max_bl - star_num / 2)))
				printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}
int main() {
	input();
	solve();
}