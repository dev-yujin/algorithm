#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//양의 정수 n에 대해서 d(n)을 n과 n의 각 자리수를 더하는 함수
int d(int num){ 
	int n_num = num;
	
	while(num != 0){
		n_num += num % 10;
		num = num / 10;
	}
	return n_num;
}

int temp = 1;
int j = 1;
vector<int> v;

int main(){
	
	while(temp <= 10000){
		if( d(temp) <= 10000){
			v.push_back(d(temp));
		} //벡터에 집어넣기
		temp ++;
	}
	sort(v.begin(), v.end()); //정렬
	
	for(int i = 0; i < v.size() ; i++){
		while(1){
			if(v[i] == j ){ //같으면 출력하지 않고 넘어감
				j++;
				break;
			}
			else{
				if(v[i] < j){ //지나간 숫자는 넘어감
					break;
				}
				else{ //안나온숫자는 출력
					printf("%d\n",j);
					j++;
				}
			}
		}
	}
	v.clear();
}

//100 까지의 셀프 넘버 : 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97