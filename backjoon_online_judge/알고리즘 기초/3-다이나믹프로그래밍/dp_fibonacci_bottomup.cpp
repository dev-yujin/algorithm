#include <iostream>

using namespace std;
int d[100] = {0,};

int fibonacci(int n){
    d[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        d[i] = d[i-1]+d[i-2];
    }
    return d[n];
}

// 3 = 1 + 2
// 2 = 0 + 1
// 1 = 1
// 0 = 0

int main(){
    int num;
    scanf("%d", &num);
    
    printf("%d\n", fibonacci(num));
    return 0;
}