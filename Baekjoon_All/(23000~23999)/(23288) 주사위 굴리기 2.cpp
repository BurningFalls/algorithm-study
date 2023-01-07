#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 20

int N, M, K;
vector<vector<int>> Map(MAX, vector<int>(MAX));
vector<vector<int>> score(MAX, vector<int>(MAX, 0));

void Calc_Score() {
	vector<int> dy = { -1, 1, 0, 0 };
	vector<int> dx = { 0, 0, -1, 1 };
	FOR(sy, 0, N - 1) {
		FOR(sx, 0, M - 1) {
			if (score[sy][sx] != 0) continue;
			queue<pii> q;
			vector<vector<int>> visited(N, vector<int>(M, 0));
			vector<pii> tmp;
			visited[sy][sx] = 1;
			q.push({ sy, sx });
			while (!q.empty()) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				tmp.push_back({ y, x });
				FOR(i, 0, 3) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
					if (visited[ny][nx]) continue;
					if (Map[ny][nx] != Map[sy][sx]) continue;
					visited[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}

			int result = Map[sy][sx] * LEN(tmp);
			for (const pii &x : tmp) {
				score[x.first][x.second] = result;
			}
		}
	}
}

void Roll(vector<int>& dice, int dir) {
	vector<vector<int>> pos(4);
	pos[0] = { 0, 1, 4, 6, 3 }; // 동
	pos[1] = { 0, 1, 5, 6, 2 }; // 북
	pos[2] = { 0, 1, 3, 6, 4 }; // 서
	pos[3] = { 0, 1, 2, 6, 5 }; // 남
	FOR(i, 0, 3) {
		if (dir != i) continue;
		FOR(j, 0, 4) {
			dice[pos[i][j]] = dice[pos[i][(j + 1) % 5]];
		}
	}
}

int Moving() {
	int result = 0;
	vector<int> dice = { 0, 1, 2, 3, 4, 5, 6 };
	vector<int> dy = { 0, -1, 0, 1 };
	vector<int> dx = { 1, 0, -1, 0 };
	int y = 0, x = 0;
	int dir = 0;
	FOR(i, 1, K) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
			dir = (dir + 2) % 4;
			ny = y + dy[dir];
			nx = x + dx[dir];
		}
		Roll(dice, dir);
		result += score[ny][nx];

		int A = dice[6];
		int B = Map[ny][nx];
		if (A > B) {
			dir = (dir + 3) % 4;
		}
		else if (A < B) {
			dir = (dir + 1) % 4;
		}

		y = ny, x = nx;
	}
	return result;
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
		}
	}

	Calc_Score();
	int ans = Moving();

	cout << ans;

	return 0;
}