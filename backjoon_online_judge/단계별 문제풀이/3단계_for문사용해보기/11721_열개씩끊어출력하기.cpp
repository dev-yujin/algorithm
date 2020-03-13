#include <iostream>
#include <string.h>

using namespace std;


string str;

int main(){
	cin >> str;
	
	for(int i = 0 ; i < str.size() ; i++){
		if(i != 0 && i%10 == 0){
			cout << '\n';
		}
		cout << str.at(i);
		
	}
	cout << '\n';
}
