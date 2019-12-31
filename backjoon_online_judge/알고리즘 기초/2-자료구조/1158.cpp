#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q, ans;
    int n, m;

    scanf("%d %d", &n, &m );

    for(int i = 1 ; i <= n ; i++){
        q.push(i);
    }

    printf("<");

    while(!q.empty()){
        for(int i = 1 ; i < m ; i++){
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        if(!q.empty()){
            // ans.push(q.front());
            if(q.size()!= 1){
                printf("%d, ", q.front());
            }
            else{printf("%d", q.front());}
            q.pop();
        }

        
    }
    printf(">\n");
    // cout << q.size() << endl;
}