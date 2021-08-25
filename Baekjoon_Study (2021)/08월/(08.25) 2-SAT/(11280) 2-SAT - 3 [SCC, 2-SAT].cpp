#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 20001

int N, M;
vector<int> edge[MAX];
int scc_num[MAX];
int visited[MAX] = { 0, };
bool finished[MAX] = { 0, };
vector<int> stored_v;
int scc_idx = 0;
int vis_idx = 0;

int CH(int x) {
	return ((x > 0) ? x * 2 - 1 : -2 * x);
}

int SCC(int node) {
	visited[node] = ++vis_idx;
	stored_v.push_back(node);
	int mini = visited[node];
	for (int next : edge[node]) {
		if (!visited[next])
			mini = min(mini, SCC(next));
		else if (!finished[next])
			mini = min(mini, visited[next]);
	}
	if (mini == visited[node]) {
		++scc_idx;
		while (true) {
			int n = stored_v.back();
			stored_v.pop_back();
			scc_num[n] = scc_idx;
			finished[n] = 1;
			if (n == node)
				break;
		}
	}
	return mini;
}

bool Check() {
	FOR(i, 1, N) {
		if (scc_num[i * 2 - 1] == scc_num[i * 2])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int u, v;
		cin >> u >> v;
		edge[CH(-u)].push_back(CH(v));
		edge[CH(-v)].push_back(CH(u));
	}
	FOR(i, 1, 2 * N) {
		if (visited[i]) continue;
		SCC(i);
	}
	cout << Check();

	return 0;
}