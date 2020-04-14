

#include <iostream>
#include <string>
#define MIN(a,b) (a<b ? a:b)

using namespace std;

int N, M; //세로 가로
int r, c, di;// 현재 위치, 방향
int A[50][50];
int ans;
/*
방향: 0, 1, 2, 3
    북, 동, 남, 서
    ^  >      <
방향에서 왼쪽 칸
    c--, r--, c++, r++
*/




void input(){
	cin >> N >> M;
    cin >> r >> c >> di;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> A[i][j];
        }
    }
}

//왼쪽으로 돌기
void turndi(){
    --di;
    if(di == -1) di = 3;
}

//보는 방향의 왼쪽 확인
int chLeft(){
    if(di == 0){
        return A[r][c-1];
    }
    if(di == 1){
        return A[r-1][c];
    }
    if(di == 2){
        return A[r][c+1];
    }
    if(di == 3){
        return A[r+1][c];
    }
}

//앞으로 한칸
void gogo(){
    if(di == 0){
        r--;
    }
    if(di == 1){
        c++;
    }
    if(di == 2){
        r++;
    }
    if(di == 3){
        c--;
    }
}

//뒤로한칸
void back(){
    if(di == 0){
        r++;
    }
    if(di == 1){
        c--;
    }
    if(di == 2){
        r--;
    }
    if(di == 3){
        c++;
    }
}

//뒤에 벽이 있나?
int isWall(){
    if(di == 0 && A[r+1][c]==1){
        
        return 1;
    }
    if(di == 1 && A[r][c-1] == 1){
        return 1;
    }
    if(di == 2 && A[r-1][c]== 1){
        return 1;
    }
    if(di == 3 && A[r][c+1] == 1){
        return 1;
    }

    return 0;
}

//청소 맵 출력
void map(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}



void solve(){
	A[r][c] = 2; //현재 위치를 청소한다
    //map();
    ans ++;
    int flag = 0; //4가 되면 네 방향 모두가 청소되었거나 벽이다

    int i = 0;
    
    while(1){
        i++;
        //왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
        if(chLeft() == 0){
            flag = 0;
            turndi();
            gogo();
            A[r][c] = 2; // 청소한다
            ans++;
            //cout << "Left : 0 , r:" << r << "  c: " << c << endl;
            //map();
            continue;
        }else if(chLeft() != 0){
            //cout << "Left : 1/2 , r:" << r << "  c: " << c << " flag :" << flag  << " di : " << di<< endl;
            if(flag < 4){
                turndi();
                flag++;
                continue;
            }
            if(flag >= 4){
                //turndi();
                if(isWall() == 1){ //벽이 있으면 작동 멈춤
                    break;
                }
                else{ //없으면 뒤로 한칸
                    flag = 0;
                    back();
                    continue;
                }
            }
        }
    }

    //map();
    cout << ans << '\n';
}


int main(){

    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	input();
	solve();
	return 0;
}
	
/*
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1 
1 0 0 0 0 0 1 1 0 1 72 -5 -8 = 59
1 0 0 0 0 0 1 1 0 1 
1 0 0 0 0 0 0 0 0 1 
1 1 1 1 1 1 1 1 1 1
*/
