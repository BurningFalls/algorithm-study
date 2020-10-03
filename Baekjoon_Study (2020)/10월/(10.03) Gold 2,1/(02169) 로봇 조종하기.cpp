#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MIN -987654321

int N, M;
int arr[1001][1001];
bool visited[1001][1001];
int cache[1001][1001][3];
int dy[3] = { 0, 0, 1 };
int dx[3] = { -1, 1, 0 };

int DP(int y, int x, int dir) {
	if (y == N && x == M)
		return arr[y][x];
	int& ret = cache[y][x][dir];
	if (ret != MIN)
		return ret;
	FOR(i, 0, 2) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny > N || nx < 1 || nx > M) continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		ret = max(ret, DP(ny, nx, i) + arr[y][x]);
		visited[ny][nx] = 0;
	}
	return ret;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
			FOR(k, 0, 2)
				cache[i][j][k] = MIN;
		}
	}
	visited[1][1] = 1;
	cout << DP(1, 1, 0);

	return 0;
}