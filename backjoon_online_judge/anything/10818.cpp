#include <iostream>
#include <stdio.h>
#define MAX(a,b) ((a>b) ? a : b)
#define MIN(a,b) ((a<b) ? a : b)

using namespace std;

int a[1000000];


int main(){
    int T, temp;
    int min = 1000000;
    int max = -1000000;
    
    scanf("%d", &T);
    for(int i = 0 ; i < T ; i++){
        scanf("%d", &temp);
        min = MIN(min, temp);
        max = MAX(max, temp);
    }

    cout << min << " " << max << '\n';

    

    return 0;
}
