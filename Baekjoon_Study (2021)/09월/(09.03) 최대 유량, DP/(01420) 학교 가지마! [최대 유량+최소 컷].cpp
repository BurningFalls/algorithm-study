#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define INF 987654321

int N, M;
char arr[101][101];
vector<int> adj[20002];
int Prev[20002];
map<pii, int> cMap;
map<pii, int> fMap;

void Connect(int from, int to) {
	cMap[{from + 1, to}] = INF;
	adj[from + 1].push_back(to);
	cMap[{to, from + 1}] = 0;
	adj[to].push_back(from + 1);

	cMap[{to + 1, from}] = INF;
	adj[to + 1].push_back(from);
	cMap[{from, to + 1}] = 0;
	adj[from].push_back(to + 1);
}

void Edge_Connection() {
	FOR(i, 0, N * M - 1) {
		cMap[{2 * i, 2 * i + 1}] = 1;
		adj[2 * i].push_back(2 * i + 1);

		cMap[{2 * i + 1, 2 * i}] = 0;
		adj[2 * i + 1].push_back(2 * i);
	}

	int from = -2;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			from += 2;
			if (arr[i][j] == '#') continue;
			if (j + 1 < M && arr[i][j + 1] != '#')
				Connect(from, from + 2);
			if (i + 1 < N && arr[i + 1][j] != '#')
				Connect(from, from + 2 * M);
		}
	}
}

int main() {
	FASTIO;
	int Sidx = -1, Eidx = -1;
	int sy = -1, sx = -1, ey = -1, ex = -1;
	int cnt = 0;
	cin >> N >> M;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> arr[i][j];
			if (arr[i][j] == 'K') {
				sy = i, sx = j;
				Sidx = cnt + 1;
			}
			else if (arr[i][j] == 'H') {
				ey = i, ex = j;
				Eidx = cnt;
			}
			cnt += 2;
		}
	}
	if ((N == 1 && M == 1) || Sidx == -1 || Eidx == -1 || abs(sx - ex) + abs(sy - ey) == 1) {
		cout << -1;
		return 0;
	}
	
	Edge_Connection();

	int ans = 0;
	while (true) {
		MEMSET(Prev, -1);
		queue<int> q;
		q.push(Sidx);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : adj[cur]) {
				if (Prev[next] != -1) continue;
				if (cMap[{cur, next}] - fMap[{cur, next}] <= 0) continue;
				q.push(next);
				Prev[next] = cur;
				if (next == Eidx)
					break;
			}
		}

		if (Prev[Eidx] == -1)
			break;
		for (int node = Eidx; node != Sidx; node = Prev[node]) {
			fMap[{Prev[node], node}] += 1;
			fMap[{node, Prev[node]}] -= 1;
		}
		ans++;
	}
	cout << ans;

	return 0;
}