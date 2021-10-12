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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

vector<vector<int>> visited(500001, vector<int>(2, -1));
queue<pii> q;

void BFS(int n, int k) {
	q.push({ n, 0 });
	visited[n][0] = 0;
	while (!q.empty()) {
		int node = q.front().first;
		int timing = q.front().second;
		q.pop();
		int next[3] = { node - 1, node + 1, node * 2 };
		int ntime = timing + 1;
		FOR(i, 0, 2) {
			if (next[i] < 0 || next[i] > 500000) continue;
			if (visited[next[i]][ntime % 2] != -1) continue;
			visited[next[i]][ntime % 2] = visited[node][timing % 2] + 1;
			q.push({ next[i], ntime });
		}
	}
}

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;

	BFS(N, K);

	int idx = 0;
	int k = K;
	int ans = -1;
	while (k <= 500000) {
		int tmp = visited[k][idx % 2];
		if (tmp != -1 && tmp <= idx) {
			ans = idx;
			break;
		}
		idx++;
		k += idx;
	}
	cout << ans;

	return 0;
}