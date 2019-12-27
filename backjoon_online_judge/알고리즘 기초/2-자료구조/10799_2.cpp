#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int valinput();
int solve();
stack<int> a;
// vector<int> s; //입력받는 문자열

int main(){
    solve();
    return 0;
}

int solve(){
    char t; //입력받는 괄호 문자열
    int index = 0; //괄호의 인덱스
    int answer = 0;
    while(1){
        scanf("%c", &t);
        if(t == '('){
            a.push(index);
        }else if(t == ')'){
            if(a.top() == index-1){ //인덱스 차이가 1이면
                //레이저임
                a.pop(); //앞 괄호 제거
                answer += a.size(); //스택의 사이즈 만큼 증가
            }else{
                //쇠막대기의 끝자락 ->  이 경우 조각이 하나 생긴다! 
                //막대기를 두번 자르는 경우 조각이 3개이므로!
                a.pop(); //막대기를 제거
                answer++;
            }
        }else{ //괄호가 아닌 경우
            printf("%d\n", answer);
            break;
        }
        index++;
    }
    return 0;
}