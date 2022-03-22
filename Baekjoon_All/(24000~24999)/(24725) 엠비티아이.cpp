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

int N, M;
vector<vector<char>> Map(201, vector<char>(201));
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int Find(int y, int x, int stage) {
	int cnt = 0;
	FOR(i, 0, 7) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (Map[ny][nx] == 'N' || Map[ny][nx] == 'S') {
			ny += dy[i];
			nx += dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (Map[ny][nx] == 'F' || Map[ny][nx] == 'T') {
				ny += dy[i];
				nx += dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (Map[ny][nx] == 'P' || Map[ny][nx] == 'J') {
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
		}
	}
	int ans = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			if (Map[i][j] == 'E' || Map[i][j] == 'I') {
				ans += Find(i, j, 0);
			}
		}
	}
	cout << ans;

	return 0;
}