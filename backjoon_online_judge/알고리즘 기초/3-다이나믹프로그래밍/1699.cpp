#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[100001];

void input(){
    cin >> N;
}

void solve(){
    for(int i = 0 ; i <= N ; i++){
        dp[i] = i; //처음에는 전부 1로 이루어짐
        for( int j = 0 ; j*j <= i ; j++){
            if(dp[i] > dp[i-j*j]+1)
                dp[i] = dp[i-j*j]+1;
        }
    }
    cout << dp[N] << '\n';
}


int main(){
    input();
    solve();
    return 0;
}