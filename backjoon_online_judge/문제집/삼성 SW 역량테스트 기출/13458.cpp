#include <iostream>
#include <string>
#define MIN(a,b) (a<b ? a:b)

using namespace std;

//총 가능한 감독의 수 100만 * 100만
// 1000 0 0000 0000
long long N;
long long B, C;
long long A[1000000];
long long subtest;
long long comp;
long long ans = 9999999999999;

void solve(){
	for(int i = 0 ; i < N ; i++){
        long long temp2 = 1; //총감독관1 + 부감독관
        long long sA = A[i]-B; //총감독관이 들어간 A

        if(sA <= 0){
            temp2 = 1;
        }
        else if(sA <= C ){
			temp2++;
		}
		else if(sA%C){
			temp2 += (sA/C + 1);
		}else{
			temp2 += (sA/C);
		}
        subtest += temp2;
	}

    cout << subtest << endl;

}

void input(){
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> A[i];
	}
	cin >> B >> C;
}

int main(){
	input();
	solve();
	return 0;
}
	
/*
12 - 2 = 10

3 4 5

2 2 3 = 7

7-2 = 5 이고
3명에서 감독만큼(2) = 3-2 = 1
이제 1명을 부감독이 보기 = 1
5 + 1 + 1

시험장 갯수  <1,000,000
감독이 3에 들어갔을 때,
4에 들어갔을 때,
5에 들어갔을 때,

100만번?

B:총감독관, C:부감독관

최종 풀이!!
각 시험장에 총감독관 1명은 꼭 들어가고, 나머지 인원을 보는 부감독관 인원이 몇명인지 계산해서 모두 더하면 됨

*/