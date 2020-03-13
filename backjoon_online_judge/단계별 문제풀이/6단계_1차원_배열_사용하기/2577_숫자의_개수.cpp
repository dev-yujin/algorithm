#include <iostream>

using namespace std;

int a,b,c;  //입력 받을 int
int total = 0 ; //곱하기 한 수
int arr[10]={0,}; //숫자가 나온 수 세기

int main(){
	
	scanf("%d%d%d",&a,&b,&c);
	
	total = a * b * c;
	
	//printf("%d\n", total);
	
	//몫이 0이 되기 전까지 10으로 나눈 나머지를 arr에 저장
	while(total != 0){  
		arr[total % 10] ++;
		total = total / 10;
	}
	
	//arr을 출력
	for(int i = 0 ; i < 10 ; i++){
		printf("%d\n",arr[i]);
	}
	
	return 0;
}