#include <iostream>

using namespace std;

int i ;

int main(){
	cin >> i;
	for(int k = 1; k <= i ; k++){
		for(int j = 1 ; j <= i ; j++){
			if(j <= i-k){
				cout << ' ';
			}
			else
				cout << '*';
		}
		cout << '\n';
	}

}
