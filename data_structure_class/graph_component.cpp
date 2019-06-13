/*
과제 4 - 연결요소 세기
2016125086 김유진
utf-8 c++ MAC
 */
#include <iostream>
#include <vector>

using namespace std;

int n, m; //n:node count , m: edge count
int a,b; //input node
vector<int> graph[101];
int check[101];  //true or false
int component;

void input(){
    cin >> n >> m;

    for( int i = 0 ; i < m ; i++){

        cin >> a >> b; //input edge

        if( (a > n)|| (b > n) || (a < 1) || (b < 1)  ){
            cout << "input node error!" << endl;
            return;
        }
        //push node
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void dfs(int index){
    check[index] = 1;  //탐색했음을 표시

    for(int i = 0 ; i < graph[index].size() ; i++){
        int temp = graph[index][i];

        if(check[temp] == 0){
            dfs(temp);
        }
    }
}

void solve(){

    for(int i = 1 ; i <= n ; i ++){
        if(check[i] == 0){  //탐색 안했으면 
            dfs(i);     //dfs
            component++;  //연결요소 증가
        }
    }

}

//print answer
void output(){
    cout << component << endl;
}

int main(){

    input();
    solve();
    output();

    return 0;

}