#include <iostream>

using namespace std;

int len = 0;
int total = 0;

int main(){
    
    cin >> len;
    char* array = new char[len];

    cin >> array;

    for(int i = 0 ; i < len ; i++){
        total += array[i] - '0';
    }
    cout << total << '\n';
}