//2522 별찍기 - 12
/*

4
   *
  **
 ***
****
 ***
  **
   *

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
	max_bl = star;
}
void solve() {
	for (int i = 1; i <= star; i++) {
		star_num = i;
		for (int j = 1; j <= max_bl; j++) {
			if ( j > max_bl - star_num ) {
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
	for (int i = star-1; i >= 1; i--) {
		star_num = i;
		for (int j = 1; j <= max_bl; j++) {
			if (j > max_bl - star_num) {
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
}
int main() {
	input();
	solve();
}
