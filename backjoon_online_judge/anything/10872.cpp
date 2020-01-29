#include <iostream>
#include <stdio.h>

using namespace std;

int fact(int n){
    if(n <= 1) return 1;
    else return n* fact(n-1);
}
int main(){
    int N;
    cin >> N;
    cout << fact(N) << '\n';
    return 0;
}