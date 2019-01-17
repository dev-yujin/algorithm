/*
    어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 수를 한수라고 한다.
    등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
    N이 주어졌을 때, 1보다 크거나 같고, 
    N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n = 0; //입력 수
vector<int> v; //자리수 자르기

int flag = 1; //수열인지 아닌지
int cnt = 0; //한수의 갯수

int sub(int n){  //자리수나누기
	int temp = 0;
	while(n != 0){
		temp = n%10;
		v.push_back(temp);
		n/=10;
	}
	return 0;
}

int iden(){
	int gap = v[1] - v[0];
	int k = 0;
	while(flag == 1){
		if(gap != v[k+1] - v[k]){
			flag = 0;
		}
		else{
			if(k == v.size()-2){
				
				break;
			}
			k++;
		}
	}
	if(v.size() == 1){
		flag = 1;
	}
	return flag;
}

int main(){
	scanf("%d",&n);
	
	for(int i = 1 ; i <= n ; i++){
		sub(i);
		iden();
		if(flag == 1){
			cnt ++;
		}
		
		//printf("%d flag : %d\n",i,iden());
		flag = 1;
		v.clear();
	}
	printf("%d\n", cnt);
}