#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 2001

int N, M;
vector<int> edge[MAX];
int visited[MAX];
bool finished[MAX];
int scc_num[MAX];
int vis_idx;
int scc_idx;
vector<int> stored_v;

int Ch(int x) {
	return ((x > 0) ? 2 * x - 1 : -2 * x);
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
		scc_idx++;
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
	if (scc_num[1] > scc_num[2])
		return false;
	FOR(i, 1, N) {
		if (scc_num[i * 2 - 1] == scc_num[i * 2])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	while (cin >> N >> M) {
		FOR(i, 1, 2 * N) {
			edge[i].clear();
			visited[i] = 0;
			finished[i] = 0;
			scc_num[i] = 0;
			vis_idx = 0;
			scc_idx = 0;
		}
		stored_v.clear();
		FOR(i, 1, M) {
			int a, b;
			cin >> a >> b;
			edge[Ch(-a)].push_back(Ch(b));
			edge[Ch(-b)].push_back(Ch(a));
		}
		FOR(i, 1, 2 * N) {
			if (visited[i]) continue;
			SCC(i);
		}
		cout << (Check() ? "yes" : "no") << "\n";
	}


	return 0;
}