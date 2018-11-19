#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> getPi(string p){
    int m = (int)p.size(), j=0;
    vector<int> pi(m, 0);
    for(int i = 1; i< m ; i++){
        while(j > 0 && p[i] !=  p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}
int compy = 0;
int kmp(string s, string p){
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j =0, cnt = 0;
    for(int i = 0 ; i < n ; i++){
        while(j>0 && s[i] != p[j]) {
            j = pi[j - 1];
            compy++;

        }
        if(i==n-1 && j<=m-1)
            break;
        if(s[i] == p[j]){
            compy++;
            if(j==m-1){
                cnt++;
                j = pi[j];
            }else{
                j++;
            }
        }

    }
    return cnt;
}
int compn = 0;
int notkmp(string s, string p){
    int n = (int)s.size(), m = (int)p.size(), cnt = 0;
    for(int i = 0 ; i < n-m+1 ; i++){
        for(int j = 0 ; j < m ; j++) {
            compn++;
            if (s[i + j] != p[j])
                break;
            if (j == m - 1) {
                s[i + j] == p[j];
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    string s, p;
    int s_num,p_num;
    cin >> s_num >> p_num;
    if(s_num < p_num || s_num > 1000000 || p_num < 1 || p_num > 100)
        printf("잘못된 범위입니다. \n");
    else {
        cin >> s;
        if(s.size() != s_num){
            printf("입력한 숫자만큼 입력하세요\n");
        }else {
            cin >> p;
            if(p.size() != p_num) {
                printf("입력한 숫자만큼 입력하세요\n");
            }else {
                auto matched = kmp(s, p);
                printf("%d %d\n", matched, compy);
                printf("%d %d\n", notkmp(s, p), compn);
            }
        }
    }
    return 0;
}