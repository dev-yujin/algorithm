#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX(a,b) (a>b ? a : b)

using namespace std;

int N;
vector<int> arr;
int dp[10000][3]; //0: 안마심, 1: 연속으로 1잔째 마실것임 , 2: 연속으로 두잔째 마실것임

void input(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int temp;
        cin >> temp ;
        arr.push_back(temp);
    }
}

void solve(){
    dp[0][1]=arr[0];
    dp[0][2]=arr[0];
    for(int i = 1; i< N ;i++){
        dp[i][0] = MAX(MAX(dp[i-1][1], dp[i-1][2]), dp[i-1][0]); //중에 최대값
        dp[i][1] = dp[i-1][0] + arr[i]; // 앞에 안마신것에 더하기
        dp[i][2] = dp[i-1][1] + arr[i]; //앞에 한잔 마신거에 더하기
    }
}

int main(){
    input();
    solve();
    cout << MAX(MAX(dp[N-1][1], dp[N-1][2]), dp[N-1][0]) << "\n";

    return 0;
}