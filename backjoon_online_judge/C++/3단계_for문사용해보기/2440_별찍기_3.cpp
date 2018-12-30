#include <iostream>

using namespace std;

int i ;

int main(){
	cin >> i;
	for(int k = i; k >= 1 ; k--){
		for(int j = 1 ; j <= k ; j++){
			cout << '*';
		}
		cout << '\n';
	}

}
