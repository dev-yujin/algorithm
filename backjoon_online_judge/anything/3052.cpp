#include <iostream>
#include <stdio.h>

using namespace std;
int arr[1000];
int main(){
    int num;
    for(int i = 0 ; i < 10 ; i++){
        cin >> num;
        
        arr[num%42]++;
    }
    int ans= 0 ;
    for(int i = 0 ; i < 1000 ; i++){
        if(arr[i]>0) ans++;
    }

    cout << ans << '\n';
    return 0;
}