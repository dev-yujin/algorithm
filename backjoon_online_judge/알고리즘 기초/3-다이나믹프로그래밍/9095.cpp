// 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
#include <iostream>

using namespace std;
int dp[11] = {0,}; //11보다 작은 수만 입력 가능
int main(){
    int T, num;
    scanf("%d", &T);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 0 ; i<T ; i++){
        scanf("%d", &num);
        for(int j = 4 ; j <= num ; j++){
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        }
        printf("%d\n", dp[num]);
    }
}