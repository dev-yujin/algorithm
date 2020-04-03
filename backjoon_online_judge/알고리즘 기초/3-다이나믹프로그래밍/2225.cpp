#include <iostream>

using namespace std;

void solve();

int N, K; //0-N까지의 숫자를 K개 더해서 N만들기
long long dp[201][201];

void input(){
    cin >> N >> K;
}

void solve(){
    // for(int i = 0 ; i <= N ; i++){
    //     dp[i][0] = 1;
    //     dp[i][1] = 1;
    // }
    dp[0][0] = 1;
    // //[0][1] [1][1]
    // dp[2][2] = 3;

    //k-1개 더해서 0-N만들것임
    for(int k = 1 ; k <= K ;k++ ){
        for(int i = 0 ; i <= N ; i++){
            for(int j= i ; j >= 0 ; j--){
                dp[i][k] += dp[j][k-1];
                dp[i][k] %= 1000000000;
            }
        }
    }
    cout << dp[N][K] << '\n';
}


int main(){
    input();
    solve();
    return 0;
}