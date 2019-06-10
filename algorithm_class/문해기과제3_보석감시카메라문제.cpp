/*
2016125086 김유진
UTF-8
C++
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
 
#define MAX 100002
 
using namespace std;
 
typedef long long ll;
 
struct INFO {
    int x, y;
    int p, q;
    INFO(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};
 
bool comp(const INFO &A, const INFO &B) {
    if (1LL * A.q * B.p != 1LL * A.p*B.q)
        return 1LL * A.q * B.p < 1LL * A.p*B.q;
 
    if (A.y != B.y)
        return A.y < B.y;
 
    return A.x < B.x;
}
 
ll ccw(const INFO &A, const INFO &B, const INFO &C) {
    return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}
 
INFO ju[MAX], p[MAX]; //ju: 보석, p: 감시카메라
 
int main() {
    int m, n; //m : 보석의 갯수 , n: 감시카메라의 갯수
    scanf("%d %d", &m, &n);
 
 //보석의 입력
    for(int i = 0 ; i < m ; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        ju[i] = INFO(x,y);
    }

 //감시카메라의 입력
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
 
        p[i] = INFO(x, y);
    }
 
    // 감시카메라를 y좌표, x좌표가 작은 순으로 정렬
    sort(p, p + n, comp);
 
    // 감시카메라의 기준점으로부터 감시카메라의 상대 위치 계산
    for (int i = 1; i < n; i++) {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
 
    // 반시계 방향으로 정렬(기준점 제외)
    sort(p + 1, p + n, comp);
 
    stack<int> s;
 
    // 스택에 first, second를 넣어준다.
    s.push(0);
    s.push(1);
 
    int next = 2;
 
    while (next < n) {
        while (s.size() >= 2) {
            int first, second;
            second = s.top();
            s.pop();
            first = s.top();
 
            // first, second, next가 좌회전 ( > 0 )이라면 second push
            // 우회전( < 0 )이라면 위의 while문 계속 반복
            if (ccw(p[first], p[second], p[next]) > 0) {
                s.push(second);
                break;
            }
        }
 
        // next push
        s.push(next++);
    }


    // 컨백스헐을 만든 감시카메라들을 새로 만듬
    int si = s.size();
    INFO ans[MAX];

    for(int i = 0; i < si ; i++){
        ans[i] = p[s.top()];
        s.pop();
    }

    //보석for start
    for(int k = 0 ; k < m ; k++){
        ans[si] = ju[k];

        // ans를 y좌표, x좌표가 작은 순으로 정렬
        sort(ans, ans + si+1, comp);

        // ans의 기준점으로부터 상대 위치 계산
        for (int i = 1; i < si+1; i++) {
            ans[i].p = ans[i].x - ans[0].x;
            ans[i].q = ans[i].y - ans[0].y;
        }
    
        // 반시계 방향으로 정렬(기준점 제외)
        sort(ans + 1, ans + si+1, comp);

        stack<int> reans; //보석의 답
    
        // 스택에 first, second를 넣어준다.
        reans.push(0);
        reans.push(1);
    
        int next2 = 2;

        int flag = 0;

        //기준점이 보석이면
        if( (ju[k].x == ans[0].x) && (ju[k].y == ans[0].y) )
        {
            flag = 1;
        }
    
        while (next2 < si+1) {
            while (reans.size() >= 2) {
                int first, second;
                second = reans.top();
                reans.pop();
                first = reans.top();
    
                // first, second, next가 좌회전 ( > 0 )이라면 second push
                // 우회전( < 0 )이라면 위의 while문 계속 반복
                if (ccw(ans[first], ans[second], ans[next2]) > 0) {
                    reans.push(second);
                    //넣는 값이 보석이면
                    if( (ju[k].x == ans[second].x) && (ju[k].y == ans[second].y) )
                    {
                        flag = 1;
                    }
                    break;
                }
            }
            // next2 push
            reans.push(next2++);
        }

        if( (reans.size() == si) && (flag == 0)){
            cout << 'Y'; 
        }
        else{
            cout << 'N';
        }
    }//보석 for end


    cout << endl;

    return 0;
}