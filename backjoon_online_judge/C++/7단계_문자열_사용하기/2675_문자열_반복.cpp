#include <iostream>
#include <string.h>

using namespace std;

string str ; //문자열

int test_case = 0 ; //케이스의 갯수
int rept = 0;   //문자열의 길이


int main(){
	
	//케이스의 갯수 입력
	scanf("%d", &test_case);
	
	for(int k= 0 ; k < test_case ; k ++){
		
		cin >> rept >> str ;
		
		for(int i = 0 ; i < str.length() ; i ++){
			for(int j = 0 ; j < rept ; j ++){
				printf("%c",str[i]);
			}
		}

		printf("\n");
	}
	
	return 0;
}