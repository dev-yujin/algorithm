#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[31];

void input(){
    cin >> N;
}

void solve(){
    dp[0] = 1;
    // dp[1] = 1;
    dp[2] = 3;
    for(int i = 4 ; i <= N ; i++){
        if(i%2 == 1){
            continue;
        }
        for(int j = 1 ; 2*j <= i ; j++){
            if( 2*j == 2){
                dp[i]+= (3 * dp[i-2*j]);
            }else{
                dp[i]+= (2 * dp[i-2*j]);
            }
        }
    }

    cout << dp[N] << '\n';
}


int main(){
    input();
    solve();
    return 0;
}