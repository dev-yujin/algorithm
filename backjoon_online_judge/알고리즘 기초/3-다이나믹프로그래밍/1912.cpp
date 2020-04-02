#include <iostream>
#include <cstring>
#include <vector>
#define MAX(a,b) ( (a>b) ? a : b)

using namespace std;

int T;
vector<int> V;
vector<int>dp;
long long m;

void input(){
    cin >> T;
    for(int i = 0 ; i < T ; i++){
        int temp;
        cin >> temp;
        V.push_back(temp);
    }
}

void solve(){
    dp.push_back(V[0]);
    m = V[0];
    for(int i = 1 ; i < T ; i++){
        int s = MAX(dp[i-1]+V[i], V[i]);
        dp.push_back(s);
        //cout << "s :" << s << '\n';
        if(m < s) m = s;
    }
    cout << m << '\n';

}

int main(){
    input();
    solve();

}