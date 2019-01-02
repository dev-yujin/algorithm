#include <iostream>



int input_num = 0;
int save = 0 ;
int cycle = 0;
int ori = 0;


int sum(int n){
    return n%10 + n/10;
}

int main(){
    scanf("%d",&input_num);
    ori = input_num;
    while(1){
        cycle++;

        save = sum(input_num)%10 + (input_num%10)*10;  

        //printf("save :%d\n",save);

        input_num = save;

        if(ori == save){
            break;
        }
    }
    printf("%d\n",cycle);




}