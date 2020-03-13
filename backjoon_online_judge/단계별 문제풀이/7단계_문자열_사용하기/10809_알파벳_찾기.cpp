#include <iostream>
#include <string.h>

using namespace std;

string word;
int arr[26] ;

int ascii = 0 ;

int main(){
	cin >> word;
	
	memset(arr, -1, sizeof(arr)); //**arr를 전부 -1로 초기화하는 방법**
	
	for(int i = 0 ; i < word.length() ; i++){
		
		//char를 int에 넣어버리면 아스키코드로 들어간다
		ascii = word[i]; 
		
		if(arr[ascii-97] == -1)
			arr[ascii-97] = i; 
	}
	//결과를 출력
	for(int j= 0 ; j < 26 ; j++){
		printf("%d ", arr[j]);
	}
	printf("\n");
	
	return 0;
}
//a = 97 ,b = 98... z = 122