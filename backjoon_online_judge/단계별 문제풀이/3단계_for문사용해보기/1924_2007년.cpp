#include <iostream>
#include <string.h>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = { "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT"};
int x, y;
int total = 0;

int main(){
    cin >> x >> y;

    for(int i = 1; i < x ; i++){
        total += month[i];
    }
    total += y;

    cout << day[total%7] << endl;
}