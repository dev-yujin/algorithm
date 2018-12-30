#include <iostream>

using namespace std;

int star = 0 ;

int main(){
	cin >> star ; 
	for(int i = star ; i >= 1 ; i-- ){
		for(int j = 1 ; j <= star ; j++){
			if(j > star-i){
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << '\n';
	}

	return 0;
}