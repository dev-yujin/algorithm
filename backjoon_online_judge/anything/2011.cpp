#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


string S;
int dp[5001];
int ch, Slen;
int mod = 1000000;

int ctoi(char a){
    return (a - '0');
}


void input(){
    cin >> S;
    Slen = S.length();

    S = " " + S; //앞에 공백 추가
    dp[0] = 1;
}

void solve(){
    if(ctoi(S[0]) == 0) return ;
    
    for(int i = 1; i <= Slen ; i++){
        int x = ctoi(S[i]);
        if(x >= 1 && x <= 9) dp[i] = dp[i-1] % mod; //한자리 암호 (이전꺼 만큼)

        if(i == 1) continue; //첫번째 글자는 두자리가 될수 없으니까 넘어감
        x = ctoi(S[i-1]) * 10 +  ctoi(S[i]); //두자리 암호 검사

        if(x >= 10 && x <= 26){ //두자리 범위이면
            dp[i] = ( dp[i] + dp[i-2] ) % mod; //두개전꺼 만큼 더하기
        }
    }
}

void pdp(){
    for(int i = 0 ; i < Slen ; i++){
        cout << dp[i] << " ";
    }
    cout << endl ;
}

int main(){
    input();
    
    solve();
    //pdp();
    cout <<  dp[Slen] << '\n';
    return 0;
}