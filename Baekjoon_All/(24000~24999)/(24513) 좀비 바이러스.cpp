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

struct NODE {
	int y;
	int x;
	int kind;
};

int N, M;
vector<vector<int>> Map(1001, vector<int>(1001));
queue<NODE> virus;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS() {
	int idx = 0;
	int prev_kind = 2;
	while (!virus.empty()) {
		int y = virus.front().y;
		int x = virus.front().x;
		int kind = virus.front().kind;
		if (prev_kind == 2 && kind == 1) {
			idx += 2;
		}
		virus.pop();
		if (Map[y][x] == -2) continue;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (Map[ny][nx] == -1 || Map[ny][nx] == -2) continue;
			if (Map[ny][nx] == kind + idx) continue;
			if (kind % 2 == 0 && Map[ny][nx] == kind + idx - 1) {
				Map[ny][nx] = -2;
			}
			else if (Map[ny][nx] == 0) {
				Map[ny][nx] = kind + idx;
				virus.push({ ny, nx, kind });
			}
		}
		prev_kind = kind;
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == 1) {
				virus.push({ i, j, Map[i][j] });
			}
		}
	}
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			if (Map[i][j] == 2) {
				virus.push({ i, j, Map[i][j] });
			}
		}
	}
	BFS();
	int one = 0, two = 0, three = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			if (Map[i][j] == -1 || Map[i][j] == 0) continue;
			if (Map[i][j] == -2) {
				three++;
			}
			else if (Map[i][j] % 2 == 1) {
				one++;
			}
			else if (Map[i][j] % 2 == 0) {
				two++;
			}
		}
	}
	cout << one << " " << two << " " << three;

	return 0;
}