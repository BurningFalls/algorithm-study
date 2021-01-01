#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 200000 + 1

int N, Q;
vector<int> v[MAX];
int visited[MAX] = { 0, };
int nodes[MAX] = { 0, };
bool is_cycle[MAX] = { 0, };
bool flag = false;

void DFS(int prev, int node, int cnt) {
	if (flag)
		return;
	int len = v[node].size();
	FOR(i, 0, len - 1) {
		if (flag)
			return;
		int nn = v[node][i];
		if (nn == prev) continue;
		if (visited[nn]) {
			int idx = cnt - 1;
			is_cycle[nn] = 1;
			while (idx >= 1 && nodes[idx] != nn) {
				is_cycle[nodes[idx]] = 1;
				idx--;
			}
			flag = true;
			continue;
		}
		visited[nn] = 1;
		nodes[cnt] = nn;
		DFS(node, nn, cnt + 1);
		visited[nn] = 0;
		nodes[cnt] = 0;
	}
}

void BFS(int node) {
	queue<int> q;
	visited[node] = node;
	q.push(node);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int len = v[cur].size();
		FOR(i, 0, len - 1) {
			int nn = v[cur][i];
			if (is_cycle[nn]) continue;
			if (visited[nn]) continue;
			visited[nn] = node;
			q.push(nn);
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> Q;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = 1;
	nodes[1] = 1;
	DFS(-1, 1, 2);
	memset(visited, 0, sizeof(visited));
	FOR(i, 1, N) {
		if (!is_cycle[i]) continue;
		BFS(i);
	}
	FOR(i, 1, Q) {
		int a, b;
		bool flag1, flag2;
		cin >> a >> b;
		flag1 = is_cycle[a];
		flag2 = is_cycle[b];
		if (flag1 && flag2)
			cout << 2;
		else {
			if (visited[a] == visited[b])
				cout << 1;
			else
				cout << 2;
		}
		cout << "\n";
	}

	return 0;
}