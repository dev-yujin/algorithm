#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stack>

using namespace std;

int main(){
    string num; //2진수 입력받음
    cin >> num;

    stack<int> st;

    if(num == "0") printf("%d", 0);
    else{
        int len = num.length(); //문자열 길이

        for(int i = len-1 ; i >= 0 ; i = i - 3){
            int sub_n = 0; //부분 숫자를 넣을 곳
            int a = 0,b = 0,c = 0;
            if(i == 1){
                c = (num.at(i) - '0')*1;
                a = (num.at(i-1) - '0')*2;
            }
            else if(i == 0){
                c = (num.at(i) - '0')*1;
            }
            else{
                c = (num.at(i) - '0')*1;
                a = (num.at(i-1) - '0')*2;
                b = (num.at(i-2) - '0')*4;
            }
            
            sub_n = a+b+c;
            // cout << sub_n;
            st.push(sub_n);
        }

    }

    while(!st.empty()){
        printf("%d",st.top());
        st.pop();
    }
    printf("\n");
    // cout << '\n';

}