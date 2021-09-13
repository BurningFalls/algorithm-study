#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

vector<int> edge[100001];
char color[100001];
int visited[100001];
int CNT[100001];

void BFS(int start, int idx) {
	queue<int> q;
	int cnt = 0;
	visited[start] = idx;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		cnt++;
		q.pop();
		for (int next : edge[node]) {
			if (color[next] == 'B') continue;
			if (visited[next]) continue;
			visited[next] = idx;
			q.push(next);
		}
	}
	CNT[idx] = cnt;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N - 1) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	FOR(i, 1, N)
		cin >> color[i];
	int idx = 0;
	FOR(i, 1, N) {
		if (color[i] == 'B') continue;
		if (visited[i]) continue;
		idx++;
		BFS(i, idx);
	}

	ll ans = 0;
	FOR(i, 1, N) {
		if (color[i] == 'R') continue;
		for (int node : edge[i]) {
			if (color[node] == 'B') continue;
			ans += CNT[visited[node]];
		}
	}
	cout << ans;

	return 0;
}