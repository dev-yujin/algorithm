#include <iostream>
#include <stack>

using namespace std;

stack<char> s1, s2;

int main(){
    char a;
    int num;
    char co, val;
    while(1){ //초기 문자열 입력
        scanf("%c",&a);
        if(a == '\n'){
            break;
        }else{
            s1.push(a);
        }
    }
    scanf("%d",&num); //명령 갯수 입력

    for(int i = 0 ; i < num ; i++){
        cin >> co;
        if(co == 'P'){ //커서의 왼쪽에 삽입
            cin >> val; //scanf(" %c", &val); 이렇게 가능
            s1.push(val);
        }
        else if(co == 'D'){ //커서를 오른쪽으로 한칸 옮김
            if(s2.size() > 0 ){ //문장의 맨 뒤가 아님 => !s2.empty() 로 대체 가능
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if(co == 'L'){ //커서를 왼쪽으로 한칸 옮김
            if(s1.size() > 0){ //문장의 맨 앞이 아님
                s2.push(s1.top());
                s1.pop();
            }
        }
        else if(co == 'B'){
            if(s1.size() > 0){
                s1.pop();
            }
        }
    }

    while(1){
        if(s1.size() != 0){
            s2.push(s1.top());
            s1.pop();
        }else{ break;}
    }

    while(1){
        if(s2.size() != 0){
            cout<< s2.top();
            s2.pop();
        }else {break;}
    }
    cout << endl;
    
    return 0;
}