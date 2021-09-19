#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int N;
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int visited[501][501] = { 0, };

void Travel(int y, int x) {
	visited[y][x]++;
	cout << y << " " << x << "\n";
	FOR(i, 0, 7) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
		if (visited[ny][nx] == 2) continue;
		Travel(ny, nx);
	}
}

int main() {
	FASTIO;
	int R, C;
	cin >> N;
	cin >> R >> C;
	if (N == 1) {
		cout << 1 << "\n";
		cout << 1 << " " << 1;
		return 0;
	}
	if (N == 2 || N == 3) {
		cout << -1;
		return 0;
	}
	cout << 2 * N * N << "\n";
	Travel(R, C);
	

	return 0;
}