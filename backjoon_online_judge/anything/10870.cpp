#include <iostream>
#include <stdio.h>

using namespace std;

int p[21];
int fi(int T){
    // if(p[T] > 0) return 1;
    // else{
        // cout << "save\n";
        if(T == 0 ) return 0;
        if(T == 1 ) return 1;
        return fi(T-1) + fi(T-2);
    // } 
}

int main(){
    int T;
    cin >> T;

    cout << fi(T) << '\n';

}