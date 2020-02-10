#include <iostream>
#include <queue>
#include <string>

using namespace std;

int T; //명령어 갯수


int main(){
    cin >> T;
    string c;
    queue<int> q;

    for(int i = 0 ; i < T ; i++){
        cin >> c;
        if(c == "push"){
            int x;
            cin >> x;
            q.push(x);
        }else if(c == "pop"){
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }else if(c == "size"){
            cout << q.size() << '\n';

        }else if(c == "empty"){
            cout << q.empty() << '\n';

        }else if(c == "front"){
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
            
        }else{ //back
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }

    }
    return 0;
}