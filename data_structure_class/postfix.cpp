//2016125086 김유진
//g++ 컴파일러 사용

//postfix -> prefix 로 잘못표기

#include <iostream>
#include <stack>
#include <cstdlib>
// #include <cstdio>

using namespace std;

string prefix(string s);
float calc(string);

int main(){
    string s ="";
    // cin >> s ;
    getline(cin,s); //한줄 입력받기(공백포함)

    //후위표기식으로 만듦 : postfix()
    //후위표기식을 계산 : calc()

    cout << calc(prefix(s)) << endl;
    // printf("%f\n", calc(prefix(s)));

    return 0;
}

//후위 표기식으로 만드는 함수
string prefix(string s){
    stack <char> st;
    st.push('#'); //마지막 문자
    string ansStr = "";

    //cout << s.size() << endl;

    for(int i = 0 ; i < s.size() ; i++){
        char ch = s.at(i);
        if((ch == '+') || (ch == '-')){// 더하기 빼기 연산자
            if((st.top()=='/')||(st.top()=='*')){
                ansStr.push_back(st.top());
                st.pop();
                st.push(ch);
            }
            else
            {
                st.push(ch);
            }
        }
        else if((ch == '*') || (ch == '/')){ //곱하기 나누기 연산자
            if((st.top()=='/')||(st.top()=='*')){
                ansStr.push_back(st.top());
                st.pop();
                st.push(ch);
            }
            else{
                st.push(ch);
            } 
        }
        else if(ch == '('){ //왼쪽 괄호, 스택에 넣기
            st.push(ch);
        }
        else if(ch == ')'){
            while(st.top() != '('){
                ansStr.push_back(st.top());
                // cout <<"st.top(): "<< st.top()<< endl;
                // cout <<"ansStr: "<< ansStr<< endl;
                st.pop();
            }
            st.pop();
        }
        else if(ch == ' '){
            //공백 : 아무일도 하지 않고 넘어감
        }
        else{ //숫자는 그냥 ansStr에 입력
            ansStr.push_back(ch);
        }
    }
    while(st.top()!='#'){ //스택에 남은 것 빼기
        ansStr.push_back(st.top());
        st.pop();
    }
    // cout << "후위표기식 : "<< ansStr<< endl;

    return ansStr;
}
/*
중위 -> 후위식 함수 만들기
1. 연산자 이면 스택에 넣는다.
    -top() 연산자와 같은(높은) 우선순위의 연산자가 나오면 스택에서 꺼내고 , 현재 읽은것을 집어 넣는다
    -현재 읽은 연산자보다 top()연산자의 우선순위가 낮으면 스택에 집어넣는다.
2. 숫자이면 ansStr에 넣는다
3. # 문자가 나오면 식 생성이 끝났음을 나타낸다.
4. 왼쪽 괄호("(")가 나오면 스택에 넣는다
5. 오른쪽괄호 (")")가 나오면 왼쪽 괄호가 나올 때 까지 스택에서 연산자를 꺼낸다.
*/

//후위표기식을 계산하는 함수
float calc(string s){
    stack <float> operand; //피연산자 스택
    char ch;
    float a,b;
    for(int i = 0 ; i < s.size() ; i++){
        ch = s.at(i);
        switch(ch){
            case '+' :
                a = operand.top();
                operand.pop();
                b = operand.top();
                operand.pop();
                operand.push(a+b);
                break;
            case '-' :
                a = operand.top();
                operand.pop();
                b = operand.top();
                operand.pop();
                operand.push(b-a);
                break;
            case '*' :
                a = operand.top();
                operand.pop();
                b = operand.top();
                operand.pop();
                operand.push(a*b);
                break;
            case '/' :
                a = operand.top();
                operand.pop();
                b = operand.top();
                operand.pop();
                operand.push(b/a);
                break;
            //연산자가 아닌 숫자인 경우
            default : 
                operand.push(atof(&ch));
                //cout << atoi(&ch) << endl;
                break;
        }
    }
    return operand.top();
}
