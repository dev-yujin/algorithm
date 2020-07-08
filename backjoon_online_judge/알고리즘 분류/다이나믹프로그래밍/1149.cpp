#include <iostream>
#include <string>
#define MIN(a,b) (a < b ? a : b)

using namespace std;

int a, r, g, b;
int d[1001][3];

int solve(){
    
    cin >> a;
    for(int i = 1 ; i <= a ; i++){
        cin >> r >> g >> b; //입력받는 동시에 처리하기
        d[i][0] = MIN(d[i-1][1], d[i-1][2]) + r; //Red 집은 이전에 Green, Blue 를 칠한것의 최소값에 더하기
        d[i][1] = MIN(d[i-1][0], d[i-1][2]) + g;
        d[i][2] = MIN(d[i-1][0], d[i-1][1]) + b;
    }

    cout << MIN(MIN(d[a][0], d[a][1]), d[a][2]) << "\n";
    return 0;
}
 

int main(){
    solve();
    return 0;
}