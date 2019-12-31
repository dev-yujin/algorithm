#include <iostream>

using namespace std;

int dp[41] = {0,};

int fibonacci(int n){
    if(n <= 1){
        dp[n] = n;
        return dp[n];
    }else
    {
        if(dp[n]>0){ //dp가 0보다 크면 이미 구한 수 이므로 다시 구하지 않는다.
            return dp[n];
        }
        else{
            dp[n] = fibonacci(n-1) + fibonacci(n-2);
            return dp[n];
        }
    }
}

int main(){
    int num, t;
    scanf("%d", &t);
    for(int i = 0 ; i< t ; i++){
        scanf("%d", &num);
        if(num == 0){
            printf("1 0\n");
        }
        else if(num == 1){
            printf("0 1 \n");
        }
        else{
            fibonacci(num);
            printf("%d %d\n", dp[num-1], dp[num]);
            //num번째 피보나치가 1의 호출횟수, num-1번째 피보나치가 0의 호출횟수가 된다
        }
    }
    return 0;
}