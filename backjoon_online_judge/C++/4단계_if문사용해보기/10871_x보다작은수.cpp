#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


int len = 0;
int t = 0;
int temp = 0;
vector<int> v;

int main(){
	scanf("%d%d", &len, &t);
	for(int i = 0 ; i < len ; i++){
		scanf("%d", &temp);
		v.push_back(temp);
	}
	
	for(int i = 0 ; i < len ; i++){
		if(v[i] < t){
			printf("%d ",v[i]);
		}
	}
	printf("\n");
	
}