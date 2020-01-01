/*
날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다. 이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 상금을 걸었다.

길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.

S = A[0]*B[0] + ... + A[N-1]*B[N-1]

S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.

S의 최솟값을 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> a, b;
    int n, temp;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &temp);
        a.push_back(temp);
    }
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &temp);
        b.push_back(temp);
    }
    // cout << a.size() << " " << b.size() << "\n";
    sort(a.begin(), a.end());
    // cout << a[0] << a[1] << a[2] << a[3] << a[4]<< endl;
    sort(b.begin(), b.end());
    // cout << b[0] << b[1] << b[2] << b[3] << b[4]<< endl;

    int sum = 0;
    for(int i = 0 ; i < n ;i++){
        sum += a[i]*b[n-i-1];
    }
    printf("%d\n", sum);

    


    return 0;
}