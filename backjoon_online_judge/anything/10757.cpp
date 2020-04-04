#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string a, b;
int min_len;
stack<int> sa, sb, ans;
// int asign, bsign, abs;
int emp; // 1 : a, 2 : b

void input(){
    cin >> a >> b;


    // reverse(a.begin(), a.end());
    // reverse(b.begin(), b.end());

    for(int i = 0 ; i < a.length() ; i ++){
        int temp = a[i] - '0';
        sa.push(temp);
    }
    for(int i = 0 ; i < b.length() ; i ++){
        int temp = b[i] - '0';
        sb.push(temp);
    }
}

void solve(){
    int carry = 0;
    while(1){

        if(sa.empty()){
            emp = 1;
            break;
        }
        if(sb.empty()){
            emp = 2;
            break;
        }

        int temp = 0;
        if(carry == 1){
            temp = (sb.top())+(sa.top()) + 1;
        }else temp = (sb.top())+(sa.top());
        

        if(temp >= 10){
            carry = 1;
            ans.push(temp%10);
        }else{
            carry = 0;
            ans.push(temp);
        }

        sa.pop();
        sb.pop();
    }

    if(emp == 1){
        while(!sb.empty()){
            int temp = 0;
            if(carry == 1){
                temp = sb.top()+1;
            }else{
                temp = sb.top();
            }

            if(temp >= 10){
                carry = 1;
                ans.push(temp%10);
            }else{
                carry = 0;
                ans.push(temp);
            }
            
            sb.pop();
        }
    }else if(emp == 2){
        while(!sa.empty()){
            int temp = 0;
            if(carry == 1){
                temp = sa.top()+1;
            }else{
                temp = sa.top();
            }

            if(temp >= 10){
                carry = 1;
                ans.push(temp%10);
            }else{
                carry = 0;
                ans.push(temp);
            }
            sa.pop();
        }
    }

    if(carry == 1) cout << 1;
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
}

void printinput(){
    while(!sa.empty()){
        cout << sa.top();
        sa.pop();
    }
    cout << endl;
}

int main(){
    
    input();
    // printinput();
    solve();



    //cout << (a[0]-'0') + (b[0]-'0') << '\n';
    return 0;
}