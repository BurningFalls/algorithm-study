#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
char Map[102][102];
bool visited[102][102] = { 0, };
priority_queue<pair<int, pair<int, int>>> pq;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int DT() {
	pq.push({ 0, {1, 1} });
	visited[1][1] = 0;
	while (!pq.empty()) {
		int crash = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (y == N && x == M)
			return crash;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			pq.push({ -(crash + (Map[ny][nx] - '0')), {ny, nx} });
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> M >> N;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	cout << DT();

	return 0;
}