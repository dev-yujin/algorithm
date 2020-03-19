#include <iostream>
#include <vector>

using namespace std;

int n;
int mod = 10007;
int dp[1001][1001]; //[자릿수][끝자리수]
int ans;

void input(){
    scanf("%d", &n);
}
void solve(){
    for(int i = 0 ; i <= 9 ; i++) dp[1][i] = 1;
    for(int i = 2; i <= n; i++){ //자릿수
        for(int j = 0 ; j <= 9 ; j++){ //끝자리수
            for(int k = 0 ; k <= j ; k++){
                dp[i][j] += dp[i-1][k];
            }
            dp[i][j] %= mod;
        }
    }

    for(int  i = 0 ; i <= 9 ; i++){
        ans += dp[n][i];
    }
    ans %= mod;
    printf("%d\n", ans);
}

int main(){
    input();
    solve();

    return 0;
}