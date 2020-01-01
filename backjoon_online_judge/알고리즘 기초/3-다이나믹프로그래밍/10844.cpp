#include <iostream>

using namespace std;


int main(){
    int num, i, j;
    long long dp[101][10] = {0,};
    long long mod = 1000000000;

    // scanf("%d", &num);
    cin >> num;

    for(i = 1 ; i < 10 ; i++){
        dp[1][i] = 1;
    }
    for(i = 2; i <= num ; i++){
        for(j = 0; j < 10 ; j++){
            dp[i][j] = 0;
            if(j == 0){
                dp[i][j] = dp[i-1][j+1];
            }
            else if(j == 9){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = (dp[i-1][j+1]+dp[i-1][j-1]);
            }
            //백준 기초 강의 솔루션
            // if(j-1 >= 0) dp[i][j] += dp[i-1][j-1];
            // if(j+1 <= 9) dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= mod;
        }
    }
    long long sum = 0;
    for(i = 0 ; i < 10 ; i++){
        sum += dp[num][i];
    }
    sum %= mod;
    cout << sum << '\n';

    return 0;
}