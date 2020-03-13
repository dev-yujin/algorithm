#include <iostream>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace std;


int ca = 0;
int stud = 0;
float temp = 0;
float avg = 0 ;
float cnt = 0 ;
float rate = 0;
vector<float> v;

int main(){
	scanf("%d", &ca); //case갯수
	
	for(int i = 0 ; i < ca ; i++){
		
		scanf("%d", &stud); //학생 수
		
		for(int j = 0 ; j < stud ; j ++){
			scanf("%f", &temp); //점수 
			v.push_back(temp); //벡터에 넣기
			avg += temp;
		}
		avg /= stud;
		//printf("%f\n", avg );
		
		for(int j = 0 ; j < stud ; j++){
			if(v[j] > avg)
			{
				cnt = cnt + 1.0;
			}
		}
		// printf("%f\n", cnt );
		
		rate = cnt / (float)stud * 100;
		printf("%.3f%%\n", round(rate*1000)/1000);
		
		cnt = 0;
		avg = 0;
        rate = 0;
        stud = 0;
        v.clear();
		
	}
	
}