#include <iostream>

using namespace std;


int main() {
	int a,b;
	cin >> a >> b;
	int ans = a*b;
	
	while(b > 0){
		cout << b%10 * a << '\n';
		
		b = b/10;
	}
	cout << ans << '\n';
	return 0;
}
