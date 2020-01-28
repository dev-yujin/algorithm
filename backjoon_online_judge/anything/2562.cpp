#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<pair<int, int> > v;
	int a, b, c;
	for(int i = 1 ; i <= 9 ; i++ ){
    	scanf("%d", &a);
		v.push_back(make_pair(a, i));
	}
	
	sort(v.begin(), v.end());
	
	cout << v[8].first << '\n' << v[8].second << '\n';
	
	
	return 0;
}
