#include <iostream>
#include <string.h>

using namespace std;

string str;
int arr[26];
int max_val = 0 ; 
int max_index = 0 ;

void input(){
	cin >> str;
}

void solve(){
	
	//arr에 알파벳에 맞는 인덱스 카운트하기
	for(int i = 0 ; i < str.length()  ; i++){
		str[i] = toupper(str[i]); //각 문자를 대문자로 변환
		arr[str[i] - 65 ] ++;
	}
	
	// 배열을 출력해보기
	// for(int i = 0 ; i < 26 ; i++){
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n");
	
	//최대값을 찾기
	for(int j = 0 ; j < 26 ; j++){
		
		//값이 크면 값과 인덱스를 저장하기
		if(arr[j] > max_val){
			max_val = arr[j];
			max_index = j;
		}
		//값이 같을 때, 음수값을 주어서 구분한다(최대값의 중복을 찾기위해)
		else if(arr[j] == max_val){
			max_index = -1;	
		}
	}
}

void result(){
	
	//index 가 -1 이면 최대값을 알 수 없다.
	if(max_index == -1){
		printf("?\n");
	}
	//정수를 이용해서 알파벳을 출력
	else{
		printf("%c\n", max_index+65);
	}
}


int main(){
	
	//배열 초기화
	memset(arr, 0, sizeof(arr));
	
	//int a = 66;
	//char b = 'A';
	
	//'A'는 정수로 66
	
	//printf("%c %d\n", a, b);
	input(); //입력받기
	solve(); //문제풀기
	result(); //결과값 출력
}
