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

int N, M, X, Y;
vector<vector<int>> Edge(1001, vector<int>());
vector<vector<bool>> visited(1001, vector<bool>(1001, 0));
vector<int> ans;

void BFS() {
	queue<pii> q;
	visited[X][0] = 1;
	q.push({ X, 0 });
	while (!q.empty()) {
		int node = q.front().first;
		int vis = q.front().second;
		q.pop();
		if (vis == Y) {
			ans.push_back(node);
		}
		else if (vis > Y) {
			break;
		}
		for (int next : Edge[node]) {
			if (visited[next][vis + 1]) continue;
			visited[next][vis + 1] = 1;
			q.push({ next, vis + 1 });
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> X >> Y;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	BFS();
	if (ans.empty()) {
		cout << -1;
	}
	else {
		sort(ALL(ans));
		for (int x : ans) {
			cout << x << " ";
		}
	}

	return 0;
}