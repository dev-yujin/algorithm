#include <iostream>
#include <vector>
#define MAX(a,b) (a> b ? a : b)

using namespace std;

vector<pair<int, int > > V;
int office[8][8];
int fake[8][8]; //복사본
int N , M; // <= 8
int cctv ;//cctv갯수
int emp; //처음 0의 갯수
int ans = 64; //최대 정답의 수
int subans;

//1위 2오른쪽 3아래 4왼쪽
void up(int x, int y, int on){
    while(x > 0){
        x--;
        if(fake[x][y] == 6) break;
        fake[x][y] += on;
    }
}
void right(int x, int y, int on){
    while(y < M-1){
        y++;
        if(fake[x][y] == 6) break;
        fake[x][y] += on;
    }
}
void down(int x, int y, int on){
    while(x < N-1){
        x++;
        if(fake[x][y] == 6) break;
        fake[x][y] += on;
    }
}
void left(int x, int y, int on){
    while(y > 0){
        y--;
        if(fake[x][y] == 6) break;
        fake[x][y] += on;
    }
}

void inmake(int x, int y, int t, int on){
    int ofi = office[x][y];
    if(ofi == 1){
        if(t == 1) up(x,y,on);
        if(t == 2) right(x,y,on);
        if(t == 3) down(x,y,on);
        if(t == 4) left(x,y,on);
    }else if(ofi == 2){
        if(t == 1){
            up(x,y,on);
            down(x,y,on);
        }
        if(t == 2){
            right(x,y,on);
            left(x,y,on);
        }
    }else if(ofi == 3){
        if(t == 1 || t == 4) up(x,y,on);
        if(t == 1 || t == 2) right(x,y,on);
        if(t == 2 || t == 3) down(x,y,on);
        if(t == 3 || t == 4) left(x,y,on);
    }else if(ofi == 4){
        if(t == 1 || t == 2 || t == 4) up(x,y,on);
        if(t == 1 || t == 2 || t == 3) right(x,y,on);
        if(t == 2 || t == 3 || t == 4) down(x,y,on);
        if(t == 1 || t == 3 || t == 4) left(x,y,on);
    }else{
        up(x,y,on);
        right(x,y,on);
        down(x,y,on);
        left(x,y,on);
    }
}

void countfake(){
    for(int i = 0 ; i< N ; i++){
        for(int j = 0 ; j < M ; j++){
            //cout << fake[i][j] << " ";
            if(fake[i][j] == 0) subans++;
        }
        //cout << '\n';
    }
    //cout << "subans : " << subans << endl;
    if(ans > subans) ans = subans; //최소값
    subans = 0;
}


void solve(int vv, int cnt){
    if(cnt == cctv){
        countfake(); //사각지대 세기
        return;
    }
    
    for(int i = vv ; i < V.size() ; i++){
        int x = V[i].first;
        int y = V[i].second;
        int tv = office[x][y];
    
        if( tv == 1 || tv == 3 || tv == 4){
            for(int t = 1 ; t <= 4 ; t++){
                inmake(x,y,t,1); //불 켜기
                solve(i+1,cnt+1);
                inmake(x,y,t,-1); //불 끄기
            }
        }
        if( tv == 2 ){
            for(int t = 1 ; t <= 2 ; t++){
                inmake(x,y,t,1);
                solve(i+1, cnt+1);
                inmake(x,y,t,-1);
            }
        }
        if( tv == 5 ){
            inmake(x,y,0,1);
            solve(i+1, cnt+1);
            inmake(x,y,0,-1);
        }
    }
}

void input(){
    cin >> N >> M;
    for(int i = 0 ; i< N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> office[i][j];
            fake[i][j] = office[i][j];
            if(office[i][j] > 0 && office[i][j] < 6 ){
                cctv++;
                V.push_back(make_pair(i,j));
            }
        }
    }
}
int main(){
    input();
    //cout << cctv <<endl;
    solve(0,0);
    cout << ans << '\n';
    return 0;
}