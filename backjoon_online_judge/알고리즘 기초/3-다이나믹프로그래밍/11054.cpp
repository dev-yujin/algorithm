#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int N;
vector<int> arr;
int size_arr;
int max_val;
vector<int> dp; //증가하는 수열
int dp2[1000]; // 감소하는 수열


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


    //거꾸로 가장 긴 증가하는 부분수열을 구한다(반대로 뒤집으면 감소하는 부분수열임)
    dp2[N-1] = 1;
    for(int i = size_arr-2 ; i>= 0 ; i--){ //현재 값 dp를 채울값
        for(int j = size_arr-1 ; j >= i ; j--){ //비교값 반복
            if(arr[j] < arr[i]){ //현재 값보다 비교값이 작으면
                if(max_val < dp2[j]){ //현재 최대값이 비교값dp보다 작으면
                    max_val = dp2[j]; //최대값을 바꾸어 줌
                }
            }
        }
        dp2[i] = max_val+1; //최대값에 1 더하기
        max_val = 0; //최대값은 초기화
    }
}
void dpp(){
    for(int i = 0 ; i < N ; i++){
        cout << dp[i] << " ";
    }
    cout << "\n";
    for(int i = 0 ; i < N ; i++){
        cout << dp2[i] << " ";
    }
    cout << "\n";
}
void printans(){
    for(int i = 0 ; i < N ; i++){
        if( max_val < dp[i]+dp2[i]-1 ){
            max_val = dp[i]+dp2[i]-1;
        }
    }
    cout << max_val << '\n';
}

int main(){
    input();
    solve();
    dpp();
    printans();

    return 0;
}