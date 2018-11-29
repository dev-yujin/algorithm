/* 알고리즘 구조
    1) 초기 염색체 집합 생성
    2) 초기 염색체들에 대한 적합도 계산
    3) 현재 염색체들로부터 자손을 생성
    4) 생성된 자손들의 적합도 계산
    5) 종료 조건 판별
    6-1) 종료 도건이 거짓인 경우, (3)으로 이동
    6-2) 종료 조건이 참인 경우, 알고리즘을 종료

    연산 정의
    -초기 염색체를 생성하는 연산
    -적합도를 계산하는 연산
    -적합도를 기준으로 염색체를 선택한는 연산
    -선택된 염색체들로부터 자손을 생성하는 연산
    -돌연변이 연산

    개발 과정1
    -초기에 100개를 랜덤으로 생성
    -현 세대의 가장 우수한 5개의 자손으로 다음 세대를 구성
    -즉 상위 5%만이 생존한다고 가정
    -돌연변이 발생 확률은 0.2%로 설정

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //random 


#define MAX 100
#define HIGH 5
#define MUTATION_RATE 0.2

int unit1[MAX][9] = {0,};
int unit2[MAX][9] = {0,};
int age = 0;

void reset();
void refresh();
void play();
void show();
void copy();


int main(){

    int i,j;
    int count = 0;
    reset();
    
    printf("----------------------------GA알고리즘------------------------------\n");
    while(1){
        age++;
        refresh();
        play();
        copy();
        show();
        for(i=0 ; i < MAX ; i++)
        {
            count+=unit2[i][0];
        }

        if(count >= MAX*8){ //종료 조건
            break;
        }
        count = 0; //count 초기화
    }

}

void reset()
{
    int i = 0;
    int j = 0;
    srand(time(NULL));
    for(i=0 ; i<MAX ; i++)
    {
        for(j=1 ; j<9 ; j++)
        {
            unit1[i][j] = rand()%2;
        }
    }
}

void refresh(){
    int i;
    for(i=0; i < MAX ; i++)
    {
        unit1[i][0] = 0;
		unit2[i][0] = 0;
    }
}


void play(){
    int a = 0;
    int b = 0;
    int c = 0;      //unit1의 index
    int change = 0;  //돌연변이 계산
    int i, j;
    //srand(time(NULL));
    for(i=0 ; i < MAX ; i++)
    {
        a = rand() % 100; //범위 : 0~99
        for( j = 1; j < 9 ; j++)
        {
            change = (int)( rand() % (int)(100/MUTATION_RATE+1) );
                    //돌연변이 확률 1%

            if(change == 1) //돌연변이
            {
                unit2[i][j] = 1 - unit1[a][j];
            }
            else        //일반적인 유전
            {
                if(unit2[i][j] == unit1[a][j])
                {
                    unit2[i][j] = unit1[a][j];
                }
                else
                {
                    c = rand() % 2;
                    unit2[i][j] = 1;
                }
            }
            if(unit2[i][j] == 1)
            {
                unit2[i][0]++; //점수 계산
            }
        }
    }
}


void copy()
{
    int i, j, k, a;
    int c = 0;      //temp 의 index
    int change = 0; //돌연변이 확률 변수

    //상위  HIGH개 선택
    int temp[HIGH][9] = {0,};
    //srand(time(NULL));
    for(i = 0 ; i < MAX ; i++)
    {
        for(k = 0 ; k < HIGH ; k++)
        {
            if(temp[k][0] < unit2[i][0]) //점수를 비교
            {
                for(a = 1 ; a < 9 ; a++)
                {
                    temp[k][a] = unit2[i][a];
                    if(temp[k][a] == 1)
                    {
                        temp[k][0]++;
                    }
                }
                break;
            }
        }
    }
    //상위 HIGH의 자손으로 MAX개를 채운다
    
    for(i = 0; i < MAX ; i++)
    {
        for(j = 1; j < 9 ; j++)
        {
            c = rand() % HIGH;  //상위 HIGH 개중 택 1
            change = (int)( rand() % (int)(100/MUTATION_RATE+1) );
            if(change == 1)
            {
                unit1[i][j] = 1 - temp[c][j]; //돌연변이
            }
            else
            {
                if(unit1[i][j] == temp[c][j])
                {
                    unit1[i][j] = temp[c][j];
                }
                else
                {
                    c = rand() % 2;
                    unit1[i][j] = c;
                }
            }
            if(unit1[i][j] == 1)//점수 계산
            {
                unit1[i][0]++;
                temp[c][0] = unit1[i][0];
            }
        }
    }
}

void show()
{
    int a, i, j;
    for(a = 0; a < MAX ; a+=5)
    {
        for(i = a ; i < a+5 ; i++)
        {
            for(j=1 ; j < 9 ; j++)
            {
                printf("%d",unit2[i][j]);
            }
            printf(" [ %d ] \t", unit2[i][0]);
        }
        printf("\n");
    }
    printf("제 %d 세대 \n",age);
}