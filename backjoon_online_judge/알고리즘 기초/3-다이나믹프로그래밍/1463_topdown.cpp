//top-down 방식을 사용
#include <iostream>

using namespace std;

int dp[100] = {0,};
int go(int n){
    if(n == 1) return 0;
    if(dp[n] > 0){
        return dp[n];
    }
    else{
        int temp;
        dp[n] = go(n-1) + 1;
        if(n%2 == 0){
            temp = go(n/2) + 1;
            if(dp[n] > temp) dp[n] = temp;
        }
        if(n%3 == 0){
            temp = go(n/3) + 1;
            if(dp[n] > temp) dp[n] = temp;
        }
        return dp[n];
    }
}

int main(){
    int num;
    scanf("%d", &num);
    printf("%d\n", go(num));
    return 0;
}