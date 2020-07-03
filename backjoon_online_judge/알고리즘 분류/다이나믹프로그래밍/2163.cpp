#include <iostream>
#include <string>

using namespace std;


int main(){
    int dp[90002] = {0};
    int a,b = 0;
    cin >> a >> b;
    int max = a*b;

    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3 ; i <= max ; i++){
        dp[i] = dp[i-1]+1;
    }
    cout << dp[max] << '\n';

    return 0;

}