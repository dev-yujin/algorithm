#include<iostream>
#include<vector>
#define MIN(a,b) (a<b ? a : b)

using namespace std;

int N, M; //도시 한변의 길이, 최대 살릴수 있는 치킨집의 수
int city[51][51];
vector<pair<int, int> > hou;
vector<pair<int, int> > chick;
vector<int> chlen;
vector<int> pick;

int sizech;
int sizehou;
int citych = 9999999999; //최종 정답

int sumchlen() {
	//계산을 할때는 미리 저장해둔 치킨집과 집의 좌표를 이용한다.
	for (int i = 0; i < pick.size(); i++) {
		//고른 치킨집의 번호만큼 반복
		int nx = chick[pick[i]].first;
		int ny = chick[pick[i]].second; //거리를 재려는 치킨집의 좌표
		for (int j = 0; j < hou.size(); j++) {
			int hx = hou[j].first;
			int hy = hou[j].second; //집의 좌표

			int temp = abs(nx - hx) + abs(ny - hy); //거리를 계산
			if (chlen[j] > temp) {
				chlen[j] = temp; //작은 값이면 넣어준다
			}
		}
	}

	int sum = 0;
	for (int j = 0; j < hou.size(); j++) {
		sum += chlen[j];
		chlen[j] = 1000000; //계산을 마친 후에는 거리를 최대거리로 늘려준다. -> 다시 사용이 가능하도록!
	}
	return sum;
}

void solve(int x, int cnt) {
	//재귀에서는 치킨집의 번호만 골라주면된다.
	//M개를 고른 순간에면 도시치킨거리를 계산해 주면 된다
	if (cnt == M) {
		citych = MIN(sumchlen(), citych);
		return; //최대를 고르면 도시치킨거리를 계산해준다.
	}

	for (int i = x; i < chick.size(); i++) {
		pick.push_back(i); //i번째 치킨집을 골라줌 
		solve(i+1, cnt + 1);
		pick.pop_back(); //i번째 치킨집을 빼줌
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			city[i][j] = a;
			if (a == 1) {
				hou.push_back(make_pair(i, j));
				chlen.push_back(1000000);
			}
			if (a == 2) {
				chick.push_back(make_pair(i, j));
			}
		}
	}
	sizech = chlen.size();
	sizehou = hou.size();
}

int main() {
	input();
	solve(0, 0);
	cout << citych << '\n';
}
