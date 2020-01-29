#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    int a, b, v;
    
    cin >> a >> b >> v;
    int da = 0;
    float ans = 0;


    ans = (float)(v-b) / (float)(a-b);

    if( (v-b) % (a-b) > 0 ) ans++;

    cout << (long)ans << '\n';

    return 0;
}

//2 1 5  day = 1     1   3 2  4 3  
/*

b는 하루치 덜 계산된다. (a간 후 답이 되면 b를 갈 필요가 없으므로)

a* ans - b(ans - 1) >= v
ans(a-b)+b >= v
ans >= (v-b)/(a-b)

*/