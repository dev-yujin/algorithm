//1987.cpp _알파벳 _ 백트래킹
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[21];
int visit[26]; //방문한 알파벳을 표시할 것임
int R,C; //행 열
int dx[] = {-1,+1,0,0};
int dy[] = {0,0,+1,-1}; //상하좌우
int answer = 0;

int solve(int x,int y, int cnt){
   //이동할 수 없는 상태가 되면 return
   /*
   CAAB
   ADCB
   */
   visit[v[x][y]] = 1; //C 방문
   int flag = 0;
   
   for(int i = 0 ; i < 4 ; i++){ //상하좌우를 볼것임
      int nx = x+dx[i];
      int ny = y+dy[i]; //상하좌우 좌표 구함
      //범위에 맞고 방문 안했으면
      if(nx >= 0 && nx < R && ny >= 0 && ny < C && visit[v[nx][ny]] == 0){
         //범위에 맞는 경우
         visit[v[nx][ny]] = 1; //방문 시키고
         solve(nx, ny, cnt+1); //들어가기
         visit[v[nx][ny]] = 0; // 나와서는 방문 취소
      }else{
         flag++;
      }
      
      if(flag==4){
         if(answer < cnt) answer = cnt;
         return 0;
      }
   }
   return 0;
}

int input(){
   cin >> R >> C;
   
   for(int i = 0 ; i < R ; i++){
      for(int  j = 0 ; j < C ; j++){
         // if(i == 0 | j == 0 | i == R | j == C ){
         //    v[i].push_back(0);
         char temp = 0;
         cin >> temp;
         v[i].push_back((temp-'0')-17); // 알파벳을 숫자로 바꿔서 저장 
         
      }
   }
   return 0;
}

int printV(){
   for(int i = 0 ; i < R ; i++){
      for(int  j = 0 ; j < C ; j++){
         int temp = 0;
         cout << v[i][j];
      }
      cout << '\n';
   }
   return 0;
}

int main() {
   
   input();
   // printV();
   solve(0,0,1);
   
   cout << answer << '\n';
   return 0;
}