#include <iostream>
#include <vector>
#define MAX(a,b) (a>b ? a : b)

using namespace std;

int N, M; // <=500
vector<vector<int> > map(500);
int ch[500][500];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int ans;
int res;

//깊이 우선으로 탐색하여 백트래킹
void dfs(int x, int y, int cnt){
    if(cnt == 4){
        ans = MAX(res, ans);
        //cout << "res : " << res << endl; 
        return ;
    }

    for(int k = 0; k < 4 ;k++){
        int a = x+dx[k];
        int b = y+dy[k];

        if(a < 0 || b < 0 || a >= N || b >= M){
            continue;
        }

        if(ch[a][b] == 0){
            res += map[a][b];
            ch[a][b] = 1;
            dfs(a,b, cnt+1);
            ch[a][b] = 0;
            res -= map[a][b];

        }
        

        
    }

}

// ㅗ모양 따로 계산해주기 (dfs로는 찾을 수 없다 한줄로 이어지지 않기 때문에)
void bfs(int x, int y){
    int temp = map[x][y];
    int c = 0;
    for(int i = 0 ; i < 4 ; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M){
            continue;
        }
        c++;
        temp+= map[nx][ny];
    }

    if(c == 4){
        for(int i = 0 ; i < 4 ; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            ans = MAX(ans, temp - map[nx][ny]);
        }

    }else if(c == 3){
        ans = MAX(ans, temp);
    }

    // if(x == 1 && y == 1){
    //     cout << "c :" << c << '\n';
    //     cout << "temp : " << temp << "\n";
    // }
}

void input(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            int temp;
            cin >> temp;
            map[i].push_back(temp);
        }
    }
}


int main(){
    input();
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            
            if(ch[i][j] == 0){
            res += map[i][j];
            ch[i][j] = 1;
            dfs(i,j,1); //한줄로 이어진 모양 찾아주기
            ch[i][j] = 0;
            res -= map[i][j];
            }
            bfs(i,j); //ㅗ 모양 찾아주기
        }
    }
    
    cout << ans << '\n';
    return 0;
}