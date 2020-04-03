#include <iostream>
#include <vector>

using namespace std;

int T, N;
long long dp[101];

void solve();

void input(){
    cin >> T;
    for(int i = 0 ; i < T ; i++){
        cin >> N;
        solve();
    }
}

void solve(){
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
for(int i = 6 ; i <= N ; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
    cout << dp[N] << '\n';
    
}


int main(){
    input();
    //solve();
    return 0;
}