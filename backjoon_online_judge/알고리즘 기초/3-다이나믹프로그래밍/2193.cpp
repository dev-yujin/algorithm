#include <iostream>
#include <vector>

using namespace std;

int n;
long long dp[91][2]; //[자릿수][끝자리수]
long long ans;

void input(){
    scanf("%d", &n);
}
void solve(){
    dp[1][1] = 1; //[1][0] 은 없음 (0으로 시작하는 수는 없다)
    for(int i = 2; i <= n; i++){ //자릿수
        // dp[2][0] = dp[1][0] + dp[1][1];
        // dp[2][1] = dp[1][0];
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    ans = dp[n][0] + dp[n][1];
    printf("%lld\n", ans);
}

int main(){
    input();
    solve();

    return 0;
}