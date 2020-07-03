#include <iostream>
#include <string>

using namespace std;

string s;
int arr[26]; //알파벳 배열

int main(){
    cin >> s;
    for(int i = 0 ; i < s.length() ; i++){
        arr[s[i]-'0' -49]++;
    }

    for(int i = 0 ; i<26 ; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}