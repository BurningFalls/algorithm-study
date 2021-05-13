#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N, M, K;
bool choose[11][11] = { 0, };
int maxi = -INF;
int Map[11][11];

bool Check(int y, int x) {
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (choose[ny][nx])
			return false;
	}
	return true;
}

void DFS(int node, int cnt) {
	if (cnt == K) {
		int sum = 0;
		FOR(i, 0, N - 1) {
			FOR(j, 0, M - 1) {
				if (!choose[i][j]) continue;
				sum += Map[i][j];
			}
		}
		maxi = max(maxi, sum);
		return;
	}
	FOR(i, node, N * M - 1) {
		if (!Check(i / M, i % M)) continue;
		choose[i / M][i % M] = 1;
		DFS(i + 1, cnt + 1);
		choose[i / M][i % M] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
		}
	}
	DFS(0, 0);
	cout << maxi;

	return 0;
}