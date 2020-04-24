#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, L, R; //지도의 한변(<=50), 범위 L~R(<=100)
int A[51][51];
int ch[51][51];

int dx[] = {1, -1, 0, 0 };
int dy[] = {0, 0, 1, -1 };
int ans;

int mov;


void bfs(int x, int y, int num) {
	int usum = 0; //연합의 총 합을 계산할것임
	vector<pair<int, int> > V; //연합의 좌표를 담을것임
	queue<pair<int,int> > Q;
	Q.push(make_pair(x, y));
	V.push_back(make_pair(x, y));
	ch[x][y] = num;
	usum += A[x][y];
 
	while (!Q.empty()) {
		int X = Q.front().first;
		int Y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue; //좌표범위에 벗어남
			if (ch[nx][ny] > 0) continue; //이미 연합임

			int gap = abs(A[nx][ny] - A[X][Y]); //차이를 구함
			if (gap >= L && gap <= R) { //차이가 범위안에 있음
				ch[nx][ny] = num;
				Q.push(make_pair(nx, ny)); //bfs용 큐
				V.push_back(make_pair(nx, ny)); //연합의 좌표를 담음
				usum += A[nx][ny]; //연합의 인구수를 더함
			}

		}
	}
	

	if (V.size() <= 1) {
		return;
	}

	int ple = usum / V.size();

	V.clear();
	usum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ch[i][j] == num) {
				A[i][j] = ple;
			}
		}
	}

	

	mov = 1; //움직일 수 있음을 뜻함
	
}


void solve() {
	int num = 0;
	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (ch[i][j] == 0) {
					bfs(i, j, ++num);
				}
			}
		}
		if (mov == 0) break;
		mov = 0;
		ans++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ch[i][j] = 0;
			}
		}
	}
}

void input() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
}

int main() {
	input();
	solve();
	cout << ans << '\n';
	return 0;
}
