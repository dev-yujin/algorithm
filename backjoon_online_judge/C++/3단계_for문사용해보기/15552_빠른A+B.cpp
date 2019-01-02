#include <iostream>
//#include <cstdio>

using namespace std;

int num = 0;
int x =0 ,y = 0;



int main(){
	scanf("%d", &num);
	
	for(int i = 0 ; i < num; i++){
		scanf("%d%d", &x, &y);
		printf("%d\n", x+y);
	}
}
