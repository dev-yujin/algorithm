// 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
//출력값이 피보나치 수열과 같다.

#include <iostream>

using namespace std;
int dp[1001] = {0,};

int main(){
    int num;
    scanf("%d", &num);
    dp[1]= 1;
    dp[2]= 2;
    for(int i = 3; i <= num ; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007; //나누는 수를 넣는 것이 안정적
    }
    printf("%d\n", dp[num]);
    return 0;
}