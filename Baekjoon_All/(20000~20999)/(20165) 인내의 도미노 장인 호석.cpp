#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MAX 102

int N, M, R;
vector<vector<int>> Map(MAX, vector<int>(MAX));
vector<vector<int>> fliped(MAX, vector<int>(MAX, 0));
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int Flip(int y, int x, int dir) {
	int cnt = 0;
	int maxi = Map[y][x];
	if (!fliped[y][x]) {
		fliped[y][x] = 1;
		cnt++;
	}
	while (maxi > 1) {
		maxi--;
		y += dy[dir];
		x += dx[dir];
		if (y < 1 || x < 1 || y > N || x > M) break;
		if (!fliped[y][x]) {
			maxi = max(maxi, Map[y][x]);
			fliped[y][x] = 1;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> N >> M >> R;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	int score = 0;
	FOR(r, 1, R) {
		int X, Y;
		char D;
		int dir = -1;
		cin >> X >> Y >> D;
		if (D == 'E') dir = 0;
		else if (D == 'W') dir = 1;
		else if (D == 'S') dir = 2;
		else if (D == 'N') dir = 3;
		score += Flip(X, Y, dir);
		cin >> X >> Y;
		fliped[X][Y] = 0;
	}
	cout << score << "\n";
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cout << (fliped[i][j] ? 'F' : 'S') << " ";
		}
		cout << "\n";
	}

	return 0;
}