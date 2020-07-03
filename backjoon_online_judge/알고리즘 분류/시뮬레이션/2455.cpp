#include <iostream>

using namespace std;

int main(){
    int a, b =0;
    int max = 0;
    int tot = 0;
    for(int  i = 0 ; i < 4 ; i++){
        cin >> a >> b;
        tot = tot -a +b;
        if(max < tot) max = tot;
    }

    cout << max << '\n';

    return 0;
}