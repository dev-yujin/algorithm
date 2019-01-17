#include <iostream>
#include <string.h>

using namespace std;

char arr[80] = " "; //ox문제 답을 입력받음
int test = 0; //case 갯수
int cu = 0 ; //누적 점수
int score = 0; //총 점수

int main(){
	scanf("%d", &test); //test case 갯수
	
	for(int i = 0 ; i < test ; i++){
		
		memset(arr, '\0', sizeof(arr)); //항상 배열을 초기화한 후 입력
		scanf("%s",arr);
		
		for(int j = 0 ; j < 80 ; j++){
			
			if( arr[j] == 'O' || arr[j] == 'X' ){
				if(arr[j] == 'O'){
					cu++;
				}
				else{	
					cu = 0 ;
				}	
				score += cu;
			}
		}
		printf("%d\n", score);
		score = 0; //점수 초기화
		cu = 0; //누적 점수 초기화
		
	}
	
	
	return 0;
}
