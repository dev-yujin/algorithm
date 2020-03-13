#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int num = 0 ;
vector<int> v;

int main(){
	for(int i = 0 ; i < 3 ; i++){
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end() );
	
	cout << v[1] << '\n';	
}
