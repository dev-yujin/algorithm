// BOJ17070 파이프 옮기기1 _ 브루트포스
#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<vector<int> > home(18);
int temp;
pair<int, int> location = make_pair(1,2); //현재위치 (처음의 한족 끝(1,2))
int shape = 0; // 현재모양 (가로0, 세로1, 대각선2) 초기에는 가로
int dx[] = {0,1,1};
int dy[] = {1,0,1}; // 가로, 세로, 대각선

/*
알고리즘 : 백트래킹

가로(0) -> 가로(0), 대각선(2)
   가로(0) : x+1, y
   대각선(2) : (x+1, y), (x+1, y+1), (x, y+1) 비어있어야 이동 가능
세로(1) -> 세로(1), 대각선(2)
   세로(1) : x, y+1
   대각선(2) : ..
대각선(2) -> 가로(0), 세로(1), 대각선(2)
*/

int solve(int x, int y, int sh){
   if(x == N && y == N){
      ans += 1;
      return 0;
   }
   for(int i = 0 ; i < 3 ; i++){
      if( sh == 0 && i == 1)continue;
      if( sh == 1 && i == 0)continue;
      int nx = x+dx[i];
      int ny = y+dy[i];
      
      if(home[nx][ny] == 1) continue; //가려는 곳이 벽이면 못감
      if(i == 2 && (home[x+1][y] || home[x][y+1])) continue;
      // cout << nx << " " << ny << endl;
      solve(nx, ny, i);
      
         //가로 세로는 한칸만, 대각선은 세칸을 확인
   }
   return 0;
}


int input(){
   cin >> N;
   for(int  i = 0 ; i < N+2 ; i++){
      for(int j = 0 ; j < N+2 ; j++){
         if(i == 0 || j == 0 || i == N+1 || j == N+1){
            home[i].push_back(1); //벽은 -1로
            continue;
         }
         cin >> temp;
         home[i].push_back(temp);
      }
   }
   
//    for(int  i = 0 ; i < N+2 ; i++){
//       for(int j = 0 ; j < N+2 ; j++){
//          cout << home[i][j] << " " ;
//       }
//       cout << '\n';
//    }
   return 0;
}

int main(){
   input();
   solve(1,2,0);
   cout << ans << "\n";
   return 0;
}