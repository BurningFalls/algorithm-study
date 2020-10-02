#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
bool Map[102][102];
int visited[102][102] = { 0, };
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
queue<pii> island_q[5001];

void Find_island(int i, int j, int idx) {
	queue<pii> q;
	q.push({ i, j });
	visited[i][j] = idx;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		int cnt = 0;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (Map[ny][nx] == 0) continue;
			if (Map[ny][nx] == 1) cnt++;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = idx;
			q.push({ ny, nx });
		}
		if (cnt != 4)
			island_q[idx].push({ y, x });
	}
}

int Time(int island_cnt) {
	int maximum = 0;
	FOR(i, 1, island_cnt) {
		int q_size = island_q[i].size();
		FOR(j, 1, q_size) {
			int y = island_q[i].front().first;
			int x = island_q[i].front().second;
			island_q[i].pop();
			FOR(k, 0, 3) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
				if (visited[ny][nx] != 0 && visited[ny][nx] != i) {
					if (visited[ny][nx] > i)
						maximum = max(maximum, 2);
					else if (visited[ny][nx] < i)
						maximum = max(maximum, 1);
				}
				if (visited[ny][nx] == 0)
					island_q[i].push({ ny, nx });
				visited[ny][nx] = i;
			}
		}
	}
	return maximum;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	int cnt = 0;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (Map[i][j] == 0) continue;
			if (visited[i][j]) continue;
			cnt++;
			Find_island(i, j, cnt);
		}
	}
	int t = 1;
	int flag;
	while (true) {
		flag = Time(cnt);
		if (flag != 0)
			break;
		t++;
	}
	cout << 2 * t - flag;

	return 0;
}