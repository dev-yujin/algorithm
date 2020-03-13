#include <iostream>
#include <stack>

using namespace std;

int main(){
    int num = 0 ;
    
    scanf("%d", &num);

    stack<pair<int,int> > s;
    int t = 0;
    for(int i = 1 ; i <= num ; i++){
       scanf("%d", &t);
        
        while(1){
            if(s.empty()){ //스택이 비어있으면 넣고 0을 출력
                printf("0 ");
                s.push(make_pair(t,i));
                break;
            }else if(s.top().first < t){ //t보다 작으면 제거
                s.pop();
            }else{ //같거나 크면 부딪힌것 -> 출력 후 입력값을 넣기
                printf("%d ", s.top().second);
                s.push(make_pair(t,i));
                break;
            }
        }
    }

    printf("\n");
    return 0;
}