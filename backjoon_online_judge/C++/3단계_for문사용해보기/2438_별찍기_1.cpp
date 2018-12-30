#include <iostream>

using namespace std;

int i ;

int main(){
	cin >> i;
	for(int k = 1; k <= i ; k++){
		for(int j = 0 ; j < k ; j++){
			cout << "*" ;
		}
		cout << '\n';
	}

}
