//에라토스테네스의 체
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> v(N+1, 0);
    int cnt = 0;
    
    for(int i = 2 ; i< N+1 ; i++){
        if(v[i] == 1) continue; //이미 지워진 숫자는 넘어감
        cnt++;
        v[i] = 1; //지운 숫자는 1로 바꿈
        // cout << "i : "<< i << '\n';
        if(cnt == K) {
            cout << i << '\n';
            return 0;
        }
        
        for(int j = i + i ; j < N+1 ; j = j+i){
            if(v[j] == 1) continue;
            cnt++;
            v[j] = 1;
            // cout << "j : "<< j << '\n';
            if(cnt == K) {
                cout << j << '\n';
                return 0;
            }
            
        }
    }


    return 0;
}