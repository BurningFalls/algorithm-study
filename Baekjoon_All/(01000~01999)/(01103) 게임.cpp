#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int Map[52][52];
int dp[52][52];
bool visited[52][52] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int DFS(int y, int x) {
	if (y < 1 || x < 1 || y > N || x > M)
		return 0;
	if (Map[y][x] == 0)
		return 0;
	if (visited[y][x]) {
		cout << -1;
		exit(0);
	}
	if (dp[y][x] != -1)
		return dp[y][x];
	visited[y][x] = 1;
	dp[y][x] = 0;
	FOR(i, 0, 3) {
		int ny = y + Map[y][x] * dy[i];
		int nx = x + Map[y][x] * dx[i];
		dp[y][x] = max(dp[y][x], DFS(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return dp[y][x];
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			char x;
			cin >> x;
			if (x == 'H')
				Map[i][j] = 0;
			else
				Map[i][j] = x - '0';
		}
	}
	cout << DFS(1, 1);

	return 0;
}