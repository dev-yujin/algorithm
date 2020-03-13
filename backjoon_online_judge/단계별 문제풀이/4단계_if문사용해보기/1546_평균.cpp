#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


int len = 0;
float ma = 0;
float temp = 0;
float total = 0;
vector<float> v;

int main(){
	scanf("%d", &len);
	for(int i = 0 ; i < len ; i++){
		scanf("%f", &temp);
		v.push_back(temp);
	}
	
	for(int i = 0 ; i < len ; i++){
		if(ma < v[i]){
			ma = v[i];
		}
	}
	
	for(int i = 0 ;i <len ; i++){
		total += (v[i]/ma *100);
	}
	
	total = total / len;
	
	printf("%.2f\n", total);
	
}