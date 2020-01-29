#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
string s[50]; //스트링 담을 배열
int main(){
    // s[0] = "config";
    int T;
    cin >> T;
    
    for(int i = 0 ; i < T ; i++){
        cin >> s[i];
    }
    if(T == 1){ //하나만 있는경우를 생각해 주어야 한다.
        cout << s[0] << '\n';
        return 0 ;
    }

    int len = s[0].length();
    string word = s[0]; //비교 대상 단어
    for(int i = 0 ; i < len ; i++ ){
        char index = s[0].at(i); //문자열의 i번째 글자에 접근
        
        for(int j = 1 ; j < T ; j++){
            if(index != s[j].at(i)){ //문자가 다르면 ?출력 
                cout << '?';
                break;
            }
            if(j == T-1){
                cout << index;
                break;
            }
        }
    }
    cout << '\n';

}