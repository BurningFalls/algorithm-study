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
#define MAX 1001

struct NODE {
	int y;
	int x;
	int l;
	int r;
};

int N, M, L, R;
vector<vector<char>> Map(MAX, vector<char>(MAX));
vector<vector<bool>> visited(MAX, vector<bool>(MAX, 0));

void BFS(int sy, int sx) {
	queue<NODE> q;
	visited[sy][sx] = 1;
	q.push({ sy, sx, L, R });
	int sup = sy - 1, sdown = sy + 1;
	while (sup >= 0 && !visited[sup][sx] && Map[sup][sx] == '0') {
		visited[sup][sx] = 1;
		q.push({ sup, sx, L, R });
		sup--;
	}
	while (sdown < N && !visited[sdown][sx] && Map[sdown][sx] == '0') {
		visited[sdown][sx] = 1;
		q.push({ sdown, sx, L, R });
		sdown++;
	}
	while (!q.empty()) {
		NODE n = q.front();
		q.pop();
		int ny = n.y, nx = n.x - 1;
		if (n.l >= 1 && nx >= 0 && !visited[ny][nx] && Map[ny][nx] == '0') {
			visited[ny][nx] = 1;
			q.push({ ny, nx, n.l - 1, n.r });
			int up = ny - 1, down = ny + 1;
			while (up >= 0 && !visited[up][nx] && Map[up][nx] == '0') {
				visited[up][nx] = 1;
				q.push({ up, nx, n.l - 1, n.r });
				up--;
			}
			while (down < N && !visited[down][nx] && Map[down][nx] == '0') {
				visited[down][nx] = 1;
				q.push({ down, nx, n.l - 1, n.r });
				down++;
			}
		}
		ny = n.y, nx = n.x + 1;
		if (n.r >= 1 && nx < M && !visited[ny][nx] && Map[ny][nx] == '0') {
			visited[ny][nx] = 1;
			q.push({ ny, nx, n.l, n.r - 1 });
			int up = ny - 1, down = ny + 1;
			while (up >= 0 && !visited[up][nx] && Map[up][nx] == '0') {
				visited[up][nx] = 1;
				q.push({ up, nx, n.l, n.r - 1 });
				up--;
			}
			while (down < N && !visited[down][nx] && Map[down][nx] == '0') {
				visited[down][nx] = 1;
				q.push({ down, nx, n.l, n.r - 1 });
				down++;
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	cin >> L >> R;
	int sy = 0, sx = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == '2') {
				sy = i; sx = j;
			}
		}
	}
	BFS(sy, sx);

	int cnt = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cnt += (visited[i][j] == 1);
		}
	}
	cout << cnt;

	return 0;
}