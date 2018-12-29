#include<iostream>
#include<string>

using namespace std;

string s;
int main(){
    for(int i = 0 ; i < 100 && !cin.eof() ; i++){
        getline(cin, s);
        cout << s << endl;
    }   
}