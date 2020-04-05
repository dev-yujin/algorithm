//다시 풀어볼 문제
//혼자 풀 어보기

#include <stdio.h>
#include <string.h>

int main() {
    int T, N, M, p, i, j, n[21], d[10001];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N); //동전 종류
        memset(n, 0, sizeof(n)); memset(d, 0, sizeof(d));
        for (i = 1; i <= N; i++) scanf("%d", &n[i]);
        scanf("%d", &M); //돈
        d[0] = 1;
        for (i = 1; i <= N; i++)  //동전 종류만큼 반복
            for (j = 0; j <= M - n[i]; j++) //돈-동전종류 1000 - 1=999
                d[j + n[i]] += d[j]; 
                /*
                    j에 n[i] 동전을 하나 더해서 만들 수 있는 경우를 j+n[i]에 더하기
                */
        printf("%d\n", d[M]);
    }
    return 0;
}