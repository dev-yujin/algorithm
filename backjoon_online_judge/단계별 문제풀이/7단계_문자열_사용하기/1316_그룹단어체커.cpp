#include <iostream>
#include <string.h>

using namespace std;

int flag[26]; //방문 플래그

int word_cnt = 0 ; //그룹단어의 갯수

int word_case = 0; //입력받을 단어의 개수
string temp; //단어를 잠시 받을 곳

void solve(){

	//알파벳 인덱스에 flag표시
	for(int i = 0 ; i < temp.length() ; i++){
		
		if(temp[i] == temp[i-1]){ //바로전 문자와 같으면 넘어가기
			continue;
		}
		else if(flag[temp[i]-97] == 1){ //이미 플래그가 있으면 이제 그룹단어가 아님
			word_cnt--;
			break;
		}
		else{ //해당 없으면 플래그를 올려주기
			flag[temp[i]-97] = 1; //a가 아스키 97
		}	
	}
}

int main(){
	
	memset(flag, 0, sizeof(flag)); //배열 초기화
	
	scanf("%d", &word_case); //단어의 개수
	word_cnt = word_case;
	
	for(int i = 0 ; i < word_case ; i++){
		cin >> temp;
		
		solve(); //문제해결
		
		memset(flag, 0, sizeof(flag)); //배열을 매번 초기화
	}
	printf("%d\n", word_cnt);
}
