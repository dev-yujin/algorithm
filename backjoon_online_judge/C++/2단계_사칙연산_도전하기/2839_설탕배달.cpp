#include<iostream>
#define MIN(A,B) ((A)<(B)?(A):(B))

using namespace std;

int i=5, j=3, k=0, l = 0;
int bo;
int main(){
    cin >> k;

    if(k%5 == 0){//5의배수
        bo = k/5;
    }  
    else if(k%5 == 3 ){
        bo = k/5 + 1;
    }
	else if(k%5 == 1){
		l = k/5 -1;
		if(l<0){
			bo = -1;
		}	
		else{
			bo = l + 2;
		}
	}
	else if(k%5 == 2){
		l = k/5 - 2;
		if(l<0){
			bo = -1;
		}	
		else{
			bo = l + 4;
		}
	}
	else if(k%5 == 4){
		l = k/5 - 1;
		if(l<0){
			bo = -1;
		}	
		else{
			bo = l + 3;
		}
	}
	
	
	if(k%3 == 0){//3의배수
        bo = MIN(bo,k/3);
    }
	else if(k%3 == 2){
		l = k/3 - 1;
		if(l<0){
			bo = MIN(bo,-1);
		}	
		else{
			bo = MIN(bo,l+1);
		}
	}
	else if(k%3 == 1){
		l = k/3 - 3;
		if(l<0){
			bo = MIN(bo,-1);
		}	
		else{
			bo = MIN(bo,l+2);
		}
	}
	
    cout << bo << endl;
}

