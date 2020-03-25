#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
pair<int, int> money[105];
//vector<pair<int, int> > money; //로하면 안되는 이유는..?
int dp[50004]; //i원을 만들수 있는가. 최대로 받을 수 있는 돈은 10만원이다.
int total;

void solve();
void input(){
    
    for(int T = 0 ; T < 3 ; T++){
        for(int i = 0 ; i < 50000 ; i++){
            dp[i] = 0;
        }
        dp[0] = 1;
    
        total = 0;

        cin >> N;
        for(int i = 0 ; i< N ; i++){
            int a, b;
            cin >> a >> b;
            money[i].first = a;
            money[i].second = b;
            // money.push_back(make_pair(a,b));
            total += a * b;
        }
        if(total % 2 == 1){ //반으로 나눠지지 않으면 0
            cout << "0\n";
            continue;
        }

        sort(money, money+N); //정렬 오름차순

        solve();
    }
    
}

void solve(){

    //가장 작은 단위의 동전으로 만들수 있는 모든 dp를 1로 만든다.
    for(int i = 1 ; i <= money[0].second ; i++){
        if(money[0].first * i > total/2) break; 
        dp[i * money[0].first] = 1;
    }
    if(dp[total/2]){
        cout << "1\n";
        return;
    }

    //cout << "\n\n";

    //이제 하나씩 넣어보면서 dp를 채운다. 이때 내림차순으로 탐색한다.
    for(int i = 1 ; i < N ; i++){
        for(int j = total/2 ; j >=0 ; j--){
            if(!dp[j]) continue; //만들수 없는 돈이면 넘어간다.
            for(int k = 1 ; k <= money[i].second ; k++){
                if(j+ k*money[i].first > total/2) break;
                dp[j+k*money[i].first] = 1;
                //cout << money[0].first * k << " ";
            }
        if(dp[total/2]) break;
    }
    if(dp[total/2]) break;
    }
    // cout << "\n\n";
    cout << dp[total/2] << '\n';

        // money.clear();
        // memset(dp, 0, sizeof(dp));
}

int main(){

    input();

    return 0;
}