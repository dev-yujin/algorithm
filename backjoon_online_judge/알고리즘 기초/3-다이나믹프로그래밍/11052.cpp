// 첫째 줄에 민규가 카드 N개를 갖기 위해 지불해야 하는 금액의 최댓값을 출력한다.

#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int dp[1001] = {0,};
int main(){
    int card, num, max;
    v.push_back(0);
    scanf("%d", &card);
    for(int i = 0 ; i< card ; i++){
        scanf("%d", &num);
        v.push_back(num);
    }

    dp[1] = v[1]; //처음에는 p1값이 최대값 : 1개를 살때 최대값
    // dp[2] = v[2]; 
    for(int i = 2 ; i <= card ; i++){
        dp[i] = v[i];
        for(int j = 1 ; j<= i/2 ; j++){//1,2,3,4,5 //dp
            int temp = 0;
            temp = dp[i-j] + dp[j];
            if(dp[i] < temp){
                dp[i] = temp;
            }
        }
    }
    printf("%d\n", dp[card]);

    
    // printf("%d\n", (int)v.size());

    return 0;
}