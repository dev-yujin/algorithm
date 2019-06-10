/*
Name : 2016125086 김유진
Encoding : UTF-8
Language : C++
 */
#include <iostream>
#include <vector>
#define max(a,b) (a)>(b) ? a : b;

using namespace std;

vector<int> arr, dp, karr;
int n, k, a;
int max_value = INT_MIN;

int solve(int n){
    if(n == 1){
        dp[n] = arr[n];
        karr[n] = 1;
    }
    else if(dp[n] != 0){
        return dp[n];
    }
    else{
        dp[n] = max(solve(n-1)+arr[n], arr[n]);
        if(dp[n] == arr[n]){
            karr[n] = 1;
        }
        else{
            karr[n] = karr[n-1] + 1;
        }
    }
    
    if( (max_value < dp[n]) && (karr[n] >= k) ){
        max_value = dp[n];
    }
    return dp[n];
    
}

int main(){

    cin >> n >> k;  

    arr.push_back(0);
    for(int i = 0 ; i < n ; i++){
        cin >> a;
        arr.push_back(a);
    }

    dp.resize(n,0);
    karr.resize(n,0);

    vector<int> v;
    int sum = 0 ;
    int t = 0;
    int time = n-k+1;
    for(int h = 1 ; h <= time ; h++){
        for(int i = 1 ; i <= n-k+1 ; i++){
            t= i;
            sum = 0;
            for(int j = 0 ; j < k ; j++){
                sum += arr[t];
                t++;
            }
            if(max_value < sum){
                max_value = sum;
            }
        }
        k++;
    }
    cout << max_value << endl;
    return 0;
}