#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	unsigned long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
	int i = 1;
	if(b >= c){
		printf( "-1\n");
		return 0;
	}
	
	
	
	//if(i == 1) i = 0;
	
	cout << a/ (c - b) + 1 << endl;
	
	return 0;
}
