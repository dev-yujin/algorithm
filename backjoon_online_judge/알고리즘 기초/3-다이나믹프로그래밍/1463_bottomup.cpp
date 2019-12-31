//bottom up 방식의 풀이
#include <iostream>

using namespace std;

int dp[1000001] = {0,};
int main(){
    int num;
    scanf("%d", &num);

    for(int i = 1 ; i <= num; i++){
        if(i == 1){
            dp[i] = 0;
        }
        else{
            dp[i] = dp[i-1]+1;
            if(i%2 == 0 && dp[i/2]+1 < dp[i]){
                dp[i] = dp[i/2]+1;
            }
            if(i%3 == 0 && dp[i/3]+1 < dp[i]){
                dp[i] = dp[i/3]+1;
            }
        }
    }

    printf("%d\n", dp[num]);

    return 0;
}