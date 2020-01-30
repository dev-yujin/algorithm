#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int main(){
    int T;
    cin >> T;
    int rop = T;
    while(T--){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < rop ; i++){
        cout << v[i] << '\n';
    }
    return 0;
}