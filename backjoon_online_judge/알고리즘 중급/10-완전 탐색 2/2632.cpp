#include <iostream>
#include <vector>

using namespace std;

int N;
int A, B;
long long ans;
vector<int> a;
vector<int> b; 
int sumA, sumB;
vector<int> make_A;
vector<int> make_B;

void canMake();
void solve();

void input(){
	cin >> N; //손님이 원하는 피자의 크기  < 2,000,000
	cin >> A >> B; //A,B피자의 조각 수  < 1,000
    
	//연속된 조각을 잘라야함
    a.push_back(0);
    b.push_back(0); //헷갈리지 않기위해 1부터 넣을것임
	
	for(int i = 0 ; i < A ; i++){
		int t;
		cin >> t;
		sumA += t;
		a.push_back(t);
	}
	for(int i = 0 ; i < B ; i++){
		int t;
		cin >> t;
		sumB += t;
		b.push_back(t);
	}
	make_A.resize(sumA+1,0); // 최대 만들수 있는 크기만큼 (크기 0 도 만들 수 있음)
	make_B.resize(sumB+1,0); //전체 크기+1 만큼 리사이즈
	
}

void canMake(){
	make_A[0] =make_B[0] = make_A[sumA] = make_B[sumB] = 1;
	
    if( A != 1 ){ //1이면 0조각인 경우와 sumA인 경우 둘만 있음 -> 더이상 계산할 필요없음 (위에서 넣음)

        //A피자에서 만들수 있는 조각의 경우
        for(int i = 1 ; i <= A ; i++ ){
            int temp, cnt;
            temp = a[i];
            make_A[temp]++; //temp 크기를 만들 수 있는 경우 1 추가
            cnt = 0;
            for(int j = i+1 ; cnt < A-2 ; cnt++){ //0인 경우와 sumA인 경우는 이미 넣었으니 중간 부분만 찾을 거임
                if(j == A+1) j = 1;  //원형이므로 A+1이 되면 1로 돌아감
                temp += a[j];
                make_A[temp]++;
                ++j;
            }
        }

    }

    if(B != 1){
            //B피자에서 만들수 있는 조각의 경우
        for(int i = 1 ; i <= B ; i++ ){
            int temp, cnt;
            temp = b[i];
            make_B[temp]++;
            cnt = 0;
            for(int j = i+1 ; cnt < B-2 ; cnt++){
                if(j == B+1) j = 1;
                temp += b[j];
                make_B[temp]++;
                ++j;
            }
        }
    }
}



void solve(){
    for(int i = 0 ; i <= N ; i++){ //N 크기의 조각을 만들것임
        int mi = N - i;
        if(mi <= sumB && i <= sumA){ // 두 크기가 모두 범위안에 있을 때만 계산하기
            ans += (make_A[i] * make_B[mi]);
        }
    }
    cout << ans << '\n'; //정답 출력
}


void printAB(){ //벡터를 출력해보는 함수
	for(int i = 0 ; i <= sumA ; i++){
		cout << make_A[i] << " ";
	}
	cout << endl;


    for(int i = 0 ; i <= sumB ; i++){
		cout << make_B[i] << " ";
	}
	cout << endl;
}

/*
만약에 1이면 조각이 1인 피자 조각의 갯수임 
2이면 1+1  이거나 2인것  

7
5 3
2 2 1 7 2
총 14임 최대 크기는 14

make_A[만들수 있는 조각의 크기] = 경우의 수
5와 1은 이어져 있음
A가 5일 때 만들어질 수 있는 경우의 수
 1 2 3 4 5
 12 23 34 45 51
 123 234 345 451 512
 1234 2345 3451 4512 5123
 12345
 
 a[] = 1 1 1 1 1
 make_A 배열 
 0 1 2 3 4 5
 1 5 5 5 5 1

수도코드
 for i 1 - 5
 	1일때 넣기 make_A[A[1]] = 1
	temp = A[0]
	cnt = 0;
 	for j = i+1 ; cnt < A-1 ; j = (j+1)%A
		temp += A[j]
		make_A[temp]++;
		cnt++;

make_B[만들수 있는 조각의 크기] = 경우의 수

solve() : 수고코드
    for i = 0   i <=N i++
    mi = N - i;
    if(mi <= sumB and i <= sumA){
        ans += make_a[i] * make_b[mi];
    }

*/


int main(){
	input();
	canMake();
	//printAB();
    solve();
	return 0;
}