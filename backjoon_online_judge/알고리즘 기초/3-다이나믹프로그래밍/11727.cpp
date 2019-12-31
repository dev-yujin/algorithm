//2×n 직사각형을 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
#include <iostream>

using namespace std;

int dp[1001] = {0,};
int main(){
    int num;
    scanf("%d", &num);

    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3 ; i <= num ; i++){
        dp[i] = (dp[i-2]*2 + dp[i-1])%10007;
    }

    printf("%d\n", dp[num]);
    
    
}
