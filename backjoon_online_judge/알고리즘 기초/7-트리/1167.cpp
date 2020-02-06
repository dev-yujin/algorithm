#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h> //memset을 사용하기 위해 꼭 필요

using namespace std;

int N;//노드의 갯수
int n, node, w; //노드의 숫자, 이어진 노드, 무게
vector<pair<int,int> > a[100001];
void input(){
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++){
        cin >> n;
        while(1){
            cin >> node;
            if(node == -1) break;
            cin >> w;
            a[n].push_back(make_pair(node, w)); //연결 노드와 비중을 저장
        }
    }
}

int check[100001];
int dist[100001];
void bfs(int start){
    queue<int> q;
    q.push(start);
    // cout << a[1][0].first;
    //바꾸는 부분은 초기화 시켜주기 : check, dist
    memset(check,0,sizeof(check));
    memset(dist,0,sizeof(dist));
    check[start] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y = 0; y < a[x].size() ; y++){
            int e = a[x][y].first;
            if(!check[e]){ //방문 안했음
                check[e] = 1; //방문을 표시
                dist[e] = dist[x]+ a[x][y].second; //x까지의 거리 + 이동한 노드의 비중
                // cout << "dist[" << e << "] = " << dist[e] << "\n";
                q.push(e);
            }
        }
    }
}

int max_dis; //가장 큰 거리를 담을 변수
int start; //bfs시작점을 담을 변수 (max_dis의 점)
void find_max(){
    max_dis = 0;
    for(int i = 1 ; i <= N ; i++){
        if(dist[i] > max_dis) {
            max_dis = dist[i]; //큰 수 구하기
            start = i;
        }
    }
}



int main(){

    input();
    bfs(1);
    find_max();
    bfs(start);

    find_max();
    cout << max_dis << '\n';


    return 0;
}