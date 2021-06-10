#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int visited[1001] = { 0, };
vector<int> edge[1001];
bool flag;

void DFS(int node) {
	for(int next : edge[node]) {
		if (visited[next] == 0) {
			visited[next] = 3 - visited[node];
			DFS(next);
		}
		else {
			if (visited[next] != 3 - visited[node])
				flag = false;
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		FOR(i, 1, N)
			edge[i].clear();
		memset(visited, 0, sizeof(visited));
		flag = true;
		FOR(i, 1, M) {
			int x, y;
			cin >> x >> y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		FOR(i, 1, N) {
			if (visited[i]) continue;
			visited[i] = 1;
			DFS(i);
		}
		cout << (flag ? "possible" : "impossible") << "\n";
	}


	return 0;
}