#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

vector<pii> v;
bool visited[101][101];

int main() {
	FASTIO;
	int T;
	int N, M;
	cin >> T;
	while (T--) {
		memset(visited, 0, sizeof(visited));
		v.clear();
		cin >> N >> M;
		int cnt = 1;
		int y = 0, x = 0;
		int dir = 0;
		v.push_back({ 0, 0 });
		visited[0][0] = 1;
		if (M % 2 == 1) {
			N -= 1;
		}
		while (cnt < M * N) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) {
				dir = 1;
			}
			else {
				visited[ny][nx] = 1;
				v.push_back({ ny, nx });
				y = ny;
				x = nx;
				cnt++;
				if (dir == 1 && y == N - 1)
					dir = 2;
				else if (dir == 1 && y == 0)
					dir = 0;
			}
		}
		if (M % 2 == 1) {
			ROF(i, M - 1, 0) {
				v.push_back({ N, i });
			}
		}
		cout << 1 << "\n";
		for (pii node : v) {
			cout << "(" << node.first << "," << node.second << ")\n";
		}
	}


	return 0;
}