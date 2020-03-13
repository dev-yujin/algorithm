#include<iostream>

using namespace std;

int i=0, j=0, k=0;
int main(){
    cin >> i >> j >> k;
    cout << (i+j)%k << endl;
    cout << ( (i%k) + (j%k) )%k << endl;
    cout << (i*j)%k << endl;
    cout << ( (i%k) * (j%k) )%k << endl;
}