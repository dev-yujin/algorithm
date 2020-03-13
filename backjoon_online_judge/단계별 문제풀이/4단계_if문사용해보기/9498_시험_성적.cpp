#include <iostream>
//#include <cstdio>

using namespace std;

int num = 0;

int main(){
	scanf("%d", &num);
	
	if(num <= 100 && num >= 90){
		printf("A\n");
	}
	else if(num < 90 && num >= 80){
		printf("B\n");
	}
	else if(num < 80 && num >= 70){
		printf("C\n");
	}
	else if(num < 70 && num >= 60){
		printf("D\n");
	}
	else
	{
		printf("F\n");
	}
}