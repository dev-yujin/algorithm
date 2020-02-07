#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int N; //노드의 갯수
vector<pair<int, int> > v[10001];

void input(){
    cin >> N;
    int n,a,b;
    for(int i = 1 ; i < N ; i++){
        cin >> n >> a >> b;

        v[n].push_back(make_pair(a,b)); //n과 연결된 a노드를 삽입 (b는 비중)
        v[a].push_back(make_pair(n,b)); //트리 양방향 그래프
    }
}

int check[10001]; //방문을 체크
int dist[10001]; //각 노드에서 거리를 체크
queue<int> q;

void bfs(int start){
    memset(dist, 0, sizeof(dist));
    memset(check, 0, sizeof(check));
    check[start] = 1;
    q.push(start);
    
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i = 0 ; i < v[x].size(); i++){
            int y = v[x][i].first;
            if(!check[y]){
                check[y] = 1;
                q.push(y);
                dist[y] = dist[x] + v[x][i].second; //부모 노드까지의 거리와 자식노드의 비중을 더함
                // cout << x << " dist[" << y << "] = " << dist[y] << "\n" ;
            }
        }
    }
}

int max_di;
int start;

void find_max(){
    max_di = 0;
    for(int i = 1 ; i <= N ; i ++){
        if(max_di < dist[i]){
            max_di = dist[i];
            start = i;
        }
    }
}

int main(){
    input();

    bfs(1);

    find_max();
    // cout << start << " " << max_di << '\n';
    bfs(start);

    find_max();

    cout << max_di << '\n';
    

    return 0;
}