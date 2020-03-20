#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#define MAX(a,b) (a>b ? a : b)

using namespace std;

int T, N;
vector<vector<int> > v(2); //괄호로 몇줄인지 설정
int dp[100001][3];

void solve();
void input(){
    scanf("%d", &T);//테스트케이스 갯수
    
    for(int i = 0 ; i < T ; i++){
        scanf("%d", &N);
        memset(dp, 0, sizeof(dp));
        v[0].clear();
        v[1].clear();
        for(int j = 0 ; j < 2; j++){ //2번 반복
            for(int k = 0 ; k < N ; k++){
                int temp = 0;
                scanf("%d", &temp);
                v[j].push_back(temp); //j번째 줄에 값 넣기
            }
        }
        solve();
    }    
}
void solve(){
    dp[0][1] = v[0][0]; //위에꺼 뜯음
    dp[0][2] = v[1][0]; //아래꺼 뜯음
    for(int i = 1 ; i < N ; i++){
        dp[i][0] = MAX(MAX(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
        dp[i][1] = MAX(dp[i-1][0], dp[i-1][2]) + v[0][i];
        dp[i][2] = MAX(dp[i-1][0], dp[i-1][1]) + v[1][i];
    }
    printf("%d\n", MAX(MAX(dp[N-1][0],dp[N-1][1]) ,dp[N-1][2]));
}

int main(){
    input();
}