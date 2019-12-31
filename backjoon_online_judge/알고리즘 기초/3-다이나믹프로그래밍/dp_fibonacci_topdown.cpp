#include <iostream>

using namespace std;

// 시간이 많이 걸리는 코드 _ 메모이제이션이 필수이다.
// int fibonacci(int n){
//     if(n <= 1){
//         return n;
//     }else
//     {
//         return fibonacci(n-1) + fibonacci(n-2);
//     }
    
// }

//memoization을 적용한 피보나치 함수
int memo[100]={0,};
int fibonacci(int n){
    if(n <= 1){
        return memo[n] = n;
    }else
    {
        if(memo[n]> 0 ) return memo[n];
        else return memo[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    
}

int main(){
    int num;
    scanf("%d", &num);
    
    printf("%d\n", fibonacci(num));
    return 0;
}