#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
char Map[52][52];
priority_queue<pair<int, pii>> pq;
bool visited[51][51][2501] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS() {
	pq.push({ 0, {1, 1} });
	visited[1][1][0] = 0;
	while (!pq.empty()) {
		int cnt = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (ny == N && nx == N)
				return cnt;
			if (Map[ny][nx] == '1') {
				if (!visited[ny][nx][cnt]) {
					visited[ny][nx][cnt] = 1;
					pq.push({ -cnt, {ny, nx} });
				}
			}
			else if (Map[ny][nx] == '0') {
				if (!visited[ny][nx][cnt + 1]) {
					visited[ny][nx][cnt + 1] = 1;
					pq.push({ -(cnt + 1), {ny, nx} });
				}
			}
		}
	}
	return 0;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	cout << BFS();

	return 0;
}