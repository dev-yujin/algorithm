#include <iostream>
#include <string.h>

using namespace std;

int arr[5] = {0,}; //학생 점수를 저장
int sum = 0 ; //점수의 총점

int main(){
	
	//점수를 입력받음
	for( int i = 0 ; i < 5 ; i++){
		scanf("%d", &arr[i]);
	}
	
	for( int j = 0 ; j < 5 ; j++){
		//40점 미만인 학생들은 보충수업으로 40점이 된다.
		if(arr[j] < 40){
			arr[j] = 40;
		}
		sum += arr[j];
	}
	printf("%d\n", sum/5);

	return 0;
}