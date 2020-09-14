#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
char Map[1001][1001];
int visited[1001][1001] = { 0, };
int vis_cnt[1000001] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int y, int x, int vis) {
	queue<pii> q;
	q.push({ y, x });
	visited[y][x] = vis;
	vis_cnt[vis]++;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
			if (Map[ny][nx] == '1') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = vis;
			vis_cnt[vis]++;
			q.push({ ny, nx });
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	int vis = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == '0' && !visited[i][j]) {
				vis++;
				BFS(i, j, vis);
			}
		}
	}

	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == '0') {
				cout << 0;
			}
			else if (Map[i][j] == '1') {
				set<int> s;
				set<int>::iterator it;
				int temp = 0;
				FOR(k, 0, 3) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
					if (Map[ny][nx] == '1') continue;
					s.insert(visited[ny][nx]);
				}
				for (it = s.begin(); it != s.end(); it++) {
					temp += vis_cnt[(*it)];
				}
				cout << (temp + 1) % 10;
			}
		}
		cout << "\n";
	}

	return 0;
}