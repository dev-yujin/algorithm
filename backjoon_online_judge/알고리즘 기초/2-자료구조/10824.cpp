#include <iostream>
#include <string>

using namespace std;
int main(){
    
    string a,b,c,d;
    cin >> a >> b >> c >> d;

    string ab = a+b;
    string cd = c+d;
    long long rab = stoll(ab);
    long long rcd = stoll(cd);
    cout << rab + rcd << '\n';

    return 0;
}