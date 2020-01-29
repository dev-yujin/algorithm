#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

string s[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
int main(){
    string num; //입력받음
    cin >> num;

    if(num == "0") cout << 0;
    else{
        int len = num.length(); //문자열 길이

        for(int i = 0 ; i < len ; i++){
            
            char c = num.at(i);
            int cc = c - '0'; //숫자로 변환
            if(i == 0){ //앞에 0을 빼고 출력하기 위함
                if(cc == 1){
                    cout << "1";
                }else if(cc == 2){
                    cout << "10";
                }else if(cc == 3){
                    cout << "11";
                }else cout << s[cc];
            }else{
                cout << s[cc];
            }
        }

    }

    cout << '\n';

}