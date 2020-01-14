#include <iostream>

using namespace std;


int main() {
	int y = 0;
	cin >> y;
	
	if((y%400 == 0) ||  ((y%4 == 0)&&(y%100 != 0)) ) cout << "1\n";
	else cout << "0\n";
	
	return 0;
}
