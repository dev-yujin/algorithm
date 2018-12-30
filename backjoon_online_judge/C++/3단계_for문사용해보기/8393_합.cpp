#include <iostream>

using namespace std;

int num;
int total = 0;

int main(){
    cin >> num;
    
    for(int i = 1; i <= num ; i++){
        total += i;
    }
    cout << total;
}