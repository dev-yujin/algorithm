/*
10448.cpp _ 유레카 이론

1000 이하
유레카 수 = n(n+1)/2 < 1000
n(n+1) < 2000 = 44*45 = 1980
n = 44

3개의 수를 더한 모든 수를 구하는 연산 비용 : 44*44*44 (시간 안에 가능)


*/
#include <iostream>
#include <string>

using namespace std;

int a, n;
int urk[45];

int set_urk();

int input(){
    
    cin >> a;
    for(int i = 0 ; i < a ; i++){
        cin >> n;
        cout << set_urk() << '\n';
    }
    return 0;
}

int init(){ //초기화
    for(int i = 1 ; i < 45 ; i++){
        urk[i] = ( i * (i+1) ) / 2;
    }
    return 0;
}

int set_urk(){ //모든 경우를 검사 (부르투 포스)
    for(int i = 1; i< 45 ; i++){
        for(int j = 1 ; j < 45 ; j++){
            for(int k = 1 ; k < 45 ; k++){
                if(urk[i]+urk[j]+urk[k] == n) //모든 경우에서 n값이 나오는지 검사
                    return 1;
            }
        }
    }
    return 0;
}

int main(){
    init();
    input();
    set_urk();
    return 0;
}