#include <iostream>
#include <cstdio>

using namespace std;

int a,b;
int main(){
    
    while( (cin >> a >> b) ){
        if( (a==0)&& (b==0)){
            return 0;
        }
        printf("%d\n", a+b);
    }
    return 0;
}