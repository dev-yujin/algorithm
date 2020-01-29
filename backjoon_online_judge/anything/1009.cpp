#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    
    int sub[] = {1,1,4,4,2,1,1,4,4,2}; //ind의 원소 갯수
    //0-9까지 제곱근의 마지막자릿수는 반복된다. 반복되는 마지막 자릿수를 배열로 만듦
    int ind[][4] = { {10}, {1}, {6,2,4,8}, {1,3,9,7}, {6,4}, {5}, {6}, {1,7,9,3}, {6,8,4,2}, {1,9} };
    // int ind[][4] = { {10}, {1}, {2,4,8,6}, {3,9,7,1}, {4,6}, {5}, {6}, {7,9,3,1}, {8,4,2,6}, {9,1} };
    int a, b, n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b;
        a = a % 10;
        b = b % sub[a];
        int ans = ind[a][b];
        
        cout << ans << '\n';
    }
    
    
    return 0;
}