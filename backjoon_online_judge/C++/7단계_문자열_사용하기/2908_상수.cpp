#include <iostream>
#include <string.h>

using namespace std;

int a = 0 ,b= 0 ; //입력받을 두수
int re_a = 0 , re_b = 0 ; //뒤집어 담을 수


int main(){
	scanf("%d%d", &a, &b);
	
	//a를 뒤집어서 re_a로 넣음
	re_a = (a%10) * 100;
	a/= 10;
	re_a += (a%10) * 10;
	a/= 10;
	re_a += a;
	
	//b를 뒤집어서 re_b로 넣음
	re_b = (b%10) * 100;
	b/= 10;
	re_b += (b%10) * 10;
	b/= 10;
	re_b += b;
	
	//결과를 출력
	if(re_a > re_b){
		printf("%d\n",re_a);
	}
	else{
		printf("%d\n",re_b);
	}
}
