#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<string> v;

    for(int i = s.size()-1 ; i >= 0 ; i--){
        string sub = s.substr(i);
        v.push_back(sub);
        // cout << sub << '\n';
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << '\n';
    }
    
    return 0;
}