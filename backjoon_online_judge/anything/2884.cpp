#include <iostream>

using namespace std;

int main(){
    int H, M;
    cin >> H >> M;

    int m = 60*H + M ;

    m = m-45;
    if(m < 0) m = 1440+m;
    H = m/60;
    M = m%60;

    cout << H << " " << M << endl;

    return 0;

}