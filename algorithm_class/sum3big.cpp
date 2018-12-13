#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n, m; //n줄 m칸
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi arr;
int maxVal = 0;

void input()
{
    arr = vvi( n , vi(m) );
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int arrV(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m){
        return 0;
    }
    else{
        return arr[i][j];
    }
}

int findMax(int i, int j){
    int k;
    int max = 0;
    max = arrV(i,j) + arrV(i-1,j) + arrV(i-2,j);
    k = arrV(i,j) + arrV(i+1,j) + arrV(i+2,j);

    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i,j-1) + arrV(i,j+1);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i-1,j) + arrV(i+1,j);
    if(max < k){    max = k;  }
    k = arrV(i,j-2) + arrV(i,j-1) + arrV(i,j);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i,j+1) + arrV(i,j+2);


    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i,j-1) + arrV(i-1,j);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i-1,j) + arrV(i,j+1);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i,j-1) + arrV(i+1,j);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i,j+1) + arrV(i+1,j);


    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i-1,j) + arrV(i-1,j+1);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i+1,j-1) + arrV(i+1,j);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i+1,j+1) + arrV(i+1,j);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i-1,j) + arrV(i-1,j-1);



    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i,j-1) + arrV(i+1,j-1);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i,j+1) + arrV(i-1,j+1);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i,j+1) + arrV(i+1,j+1);
    if(max < k){    max = k;  }
    k = arrV(i,j) + arrV(i,j-1) + arrV(i-1,j-1);
    if(max < k){    max = k;  }
    
    return max;
}

void printResult(){
    cout << maxVal << endl;
}

int main()
{
    int la;
    cin >> n >> m;
    input();
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            la = findMax(i, j);
            if(maxVal < la )
                maxVal = la;
        }
    }
    printResult();

    return 0;
}