#include <string>
#include <iostream>

using namespace std;

int main(){
    string str;
    cin >> str;
    int len = 0;
    for(int i = str.length()-1 ; i >= 0 ;i--){
        len++;
    }
    cout << len << '\n';
    return 0;
}