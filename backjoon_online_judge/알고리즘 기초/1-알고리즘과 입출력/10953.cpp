#include <iostream>
#include <cstdio>

using namespace std;

int t ; //test case
int a,b;
char s;
int main(){
    scanf("%d", &t);
    
    for(int i = 0 ; i < t ; i++){
        scanf("%1d%1s%1d", &a,&s, &b);
        printf("%d\n", a+b);
    }
    return 0;
}