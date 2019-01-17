#include <iostream>
#include <string.h>

using namespace std;

string str; //입력받을 string
int arr[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int t[10] = {11,2,3,4,5,6,7,8,9,10};

int sec = 0 ;

int main(){
	cin >> str;
	
	//A = 65
	for(int  i = 0 ; i < str.length() ; i++){
		sec += t[ arr[ str[i]-65 ] ];
	}
	printf("%d\n",sec);	
}