#include <iostream>
#include <queue>

using namespace std;

int N, K; //수빈, 동생 위치
#define MAX 100000

int visit[MAX+1];

int main(){
    cin >> N >> K;

    if(N == K){
        cout << "0\n";
        return 0;
    }

    queue<int> q;
    q.push(N);
    int depth = 0;
    
    visit[N] = 1;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0 ; i < size ; i++){
            int x = q.front();
            q.pop();
    
            if(x == K){
                cout << depth << '\n';
                // return 0;
                queue<int> empty; q = empty;
                break;
            }

            if(x+1 <= MAX && visit[x+1] == 0){
                visit[x+1] = 1;
                q.push(x+1);
            }
        
            if(x-1 >= 0 && visit[x-1] == 0){
                visit[x-1] = 1;
                q.push(x-1);
            }

            if(x*2 <= MAX && visit[x*2] == 0){
                visit[x*2] = 1;
                q.push(x*2);
            }
        
        }
        depth++;
        
    }
    return 0;
}

/*
note
- bfs는 queue를 사용
- parameter(root)를 보통 사용

수빈이 할 수 있는 행동
1. +1
2. -1
3. *2
*/
