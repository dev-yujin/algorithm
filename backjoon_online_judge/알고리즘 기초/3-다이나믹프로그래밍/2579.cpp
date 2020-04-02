#include <iostream>
#include <cstring>
#include <vector>
#define MAX(a,b) ( (a>b) ? a : b)

using namespace std;

vector<int> V;
int dp[300][3];
int T;

void input(){
    cin >> T;
    for(int i = 0 ; i < T ; i++){
        int temp;
        cin >> temp;
        V.push_back(temp);
    }
}

void solve(){
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = V[0];

    for(int i = 1 ; i < T ; i++){
        dp[i][0] = MAX(dp[i-1][2],dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + V[i];
        dp[i][2] = dp[i-1][1] + V[i];
    }
    cout << MAX( dp[T-1][1] , dp[T-1][2] ) << '\n';

}

int main(){
    input();
    solve();

}