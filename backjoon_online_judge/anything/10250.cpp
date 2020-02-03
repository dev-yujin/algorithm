#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int H, W, N, T;
    cin >> T;
    while(T--){
        cin >> H >> W >> N;

        int x, y;
        x = N / H; //몫
        y = N % H; //나머지
        if( y > 0 ) x++;
        if( y == 0) y = H;

        int ans = y*100 + x;

        cout << ans << '\n';
    }
}