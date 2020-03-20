#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int N;
vector<int> v; //팀을 가르는 배열
vector<int> v2; //나머지 사람들을 놓는 배열
int visit[20]; //방문을 표시
int arr[20][20]; //입력받는 배열
int ans = 987654321;

void make_team(){
    for(int i = 0 ; i < N ; i++){ //나머지 팀원들 넣기
        if(visit[i] == 0)
            v2.push_back(i);
    }

    int first = 0;
    int second = 0;
    //점수 계산하고 비교하기
    for(int i=0; i< N/2 ; i++){  //팀원의 모든 조합을 더하기
        for(int j = 0 ; j < N/2 ; j++){
            first += arr[v[i]][v[j]];
            second += arr[v2[i]][v2[j]];
        }
    }
    //최소값을 설정
    if(ans > abs(first-second)) ans = abs(first-second);
    
}

void printv(){
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << " ";
    } 
    cout << " : ";
    for(int i = 0 ; i < v2.size() ; i++){
        cout << v2[i] << " ";
    }
    cout << "\n";

    //cout << ans << '\n';
}


//조합 구현하기 ( next_permutation을 사용하기도 함)
void DFS(int idx, int cnt){
    if(cnt == N/2){ //팀원이 반 이 되는 순간 점수를 계산
        make_team();
        //printv();
        v2.clear();
        return;
    }
    for(int i = idx; i < N ; i++){ //idx부터 시작하는 경우의 수를 볼것임
        if(visit[i] != 1){ //방문 안했으면 방문 표시
            visit[i] =1;
            v.push_back(i);

            DFS(i+1 , cnt+1); //i가 시작인 다음 번째 원소 탐색

            visit[i] = 0; //출력한 후 복귀하면 방문을 안했음으로 바꿈
            v.pop_back(); 
        }
    }
}


void input(){
    cin >> N; //n명
    for(int i = 0 ; i< N ; i++){
        for(int j= 0 ; j < N ; j++){
            cin >> arr[i][j];
        }
    }
}

int main(){    
    input();

    DFS(0,0);

    cout << ans << "\n";

    return 0;
}