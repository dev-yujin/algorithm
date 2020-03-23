#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX(a,b) (a>b ? a : b)

using namespace std;

int N;
vector<int> arr;
int size_arr;
int max_val;
vector<int> dp;

void input(){
   cin >> N;
   for(int i = 0 ; i < N ;i++){
       int temp;
       cin >> temp;
       arr.push_back(temp);       
   }
   size_arr = arr.size();
}

void solve(){

    dp.push_back(1);
    for(int i = 1 ; i< size_arr ; i++){ //현재 값 dp를 채울값
        for(int j = 0 ; j < i ; j++){ // 비교값 반복
            if(arr[j] < arr[i]){ //현재 값보다 비교값이 작으면
                if(max_val < dp[j]){ //현재 최대값이 비교값dp보다 작으면
                    max_val = dp[j]; //최대값을 바꾸어 줌
                }
            }
        }
        dp.push_back(max_val+1); //최대값에 1 더하기
        max_val = 0; //최대값은 초기화
    }
}
void dpp(){
    for(int i = 0 ; i < dp.size() ; i++){
        cout << dp[i] << " ";
    }
    cout << "\n";
}
void printans(){
    for(int i = 0 ; i < N ; i++){
        if( max_val < dp[i] ){
            max_val = dp[i];
        }
    }
    cout << max_val << '\n';
}

int main(){
    input();
    solve();
    //dpp();
    printans();

    return 0;
}