/*
2016125086 김유진
UTF-8      C++     MAC

과제에서 주어진 예제(example)는 
input : 6
      3 1 2 4 5 6
output : 4      이다.

이는 트리(tree)로 만들면 
      3
    1    4
      2    5
              6   이므로 과제처럼 높이(height)를 가장 긴 경로를 잇는 에지(edge)의 갯수라고 정의한다면
                              높이(height)는 3이다.
    
    검색결과 트리의 높이는 루트로부터 가장 멀리 떨어진 노드와의 거리로 정의된다.
    이를 기준으로 작성하였다.
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
    struct node *p;
}NODE;

int max_height = 0;  //maximum height
int h = 0; //current height
int n, a;

// key node insert in tree
void insert_node( NODE **t, int key)
{
    NODE *n     = (NODE *)malloc(sizeof(NODE));
    NODE *temp  = *t; // temporary node.

    h = 0;   //init height
    n->key  = key;
    n->p    = NULL;
    n->left = NULL;
    n->right= NULL;

    //if node t is null
    if( temp == NULL )
    {
        *t  = n;
        return;
        //current height is 0 
    }

    //search node position
    while( temp != NULL )
    {
        n->p    = temp;
        
        if( (temp->key) > key){
            temp    = temp->left;
            h++;   //add height, add edge
        }
        else{
            temp    = temp->right;
            h++; //add height , add edge
        }
    }

    //insert tree
    if( (n->p)->key > key){
        (n->p)->left = n;
    }
    else{
        (n->p)->right = n;
    }
   //update max height
   max_height = max(max_height, h);
}

NODE *root  = NULL;
void input(){
    cin >> n;  //input node count
    for(int i = 0 ; i < n ; i++){
        cin >> a;   //input node
        insert_node( &root, a);  //insert
    }
}

void output(){
    cout << max_height << endl;   //print tree's height
}

int main(){
    input();
    output();
}