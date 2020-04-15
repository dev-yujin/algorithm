//14502 연구소
#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#define MAX(a,b) (a>b ? a : b)

using namespace std;

int N, M; //map의 세로 가로
vector<vector<int> > vmap(8); //입력받는 원본 map
vector<pair<int,int> > virus; //입력받을 때, 바이러스가 있는 부분 좌표를 입력
vector<vector<int> > fakemap(8); //bfs할때마다 복사하는 맵
queue<pair<int, int> > q; //bfs에서 바이러스를 확산시킬때 사용
int nx[] = {1, -1, 0, 0}; 
int ny[] = {0, 0, -1, 1}; //bfs좌표를 위한 것

//0은 빈칸, 1은 벽, 2는 바이러스
//벽 3개를 무조건 세워야한다, 안전지역영역의 최대값 구하기

int ans; //정답

void printmap(); //map을 출력할 수 있다

void bfs(){ //벽을 세운 후 바이러스를 퍼뜨리는 부분
    
    //원본 map과 virus를 복사하는 과정
   for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            fakemap[i].push_back(vmap[i][j]);
        }
    }
    for(int i = 0 ; i < virus.size() ; i++){
        q.push(virus[i]);
    }
    
    //bfs과정
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //네방향으로 검사
        for(int i = 0 ; i < 4 ; i++){
            int sx = x+nx[i];
            int sy = y+ny[i];

            //좌표 범위 검사
            if(sx < 0 || sx >= N || sy < 0 || sy >= M)
                continue;

            if(fakemap[sx][sy] == 0){
                fakemap[sx][sy] = 2; //바이러스가 됨
                q.push(make_pair(sx, sy));
            }
            
        }

    }

    int res = 0; 
    //안전지대 갯수 세기
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(fakemap[i][j] == 0){
                res++;
            }
        }
    }

    //맵 초기화
    for(int i = 0 ; i < 8 ; i++){
        fakemap[i].clear();
    }
    ans = MAX(res , ans);
}


//벽을 세우는 것 : x는 행 인덱스, cnt는 세운 벽의 수
void dfs(int x, int cnt){ //완전탐색
    if(cnt == 3){ //벽을 세개 세운 순간  안전지역을 계산한다.
        bfs();
        return ;
    }

    for(int i = x ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(vmap[i][j] == 0){
                vmap[i][j] = 1; //벽을 세움
                dfs(i, cnt+1);
                vmap[i][j] = 0; //다시 벽을 치움
            }
        }
    }
    
}


void input(){
    //연구소 입력받기
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            int temp;
            cin >> temp;
            vmap[i].push_back(temp);
            if(temp == 2){ //바이러스의 위치를 삽입
                virus.push_back(make_pair(i,j));
            }
        }
    }
}

void printmap(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cout << fakemap[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    input();
    dfs(0,0);
    cout << ans << '\n';
    return 0;
}