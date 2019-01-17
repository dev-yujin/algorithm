#include <iostream>
#include <string.h>

using namespace std;

int arr[8] = {0,};
int mixed_flag = 0; //flag 사용
int num = 8;

int main(){
	
	//입력받기
	for( int i = 0 ; i< 8 ; i++){
		scanf("%d", &arr[i]);
	}
	
	//처음 원소가 1이면
	if(arr[0] == 1){
		for(int j = 0 ; j < 8 ; j++){
			//오른차순이 아니면 flag on
			if(arr[j] != j+1){
				mixed_flag = 1;
			}
		}
		if(mixed_flag == 0){
			printf("ascending\n");
		}
		else{
			printf("mixed\n");
		}
	}
	//처음 원소가 8이면
	else if(arr[0] == 8){
		for(int j = 0 ; j < 8 ; j++){
			//내림차순이 아니면 flag on
			if(arr[j] != num){
				mixed_flag = 1;
			}
			num--;
		}
		if(mixed_flag == 0){
			printf("descending\n");
		}
		else{
			printf("mixed\n");
		}
	}
	//둘다 아니면
	else{
		printf("mixed\n");
	}
    
	return 0;
}