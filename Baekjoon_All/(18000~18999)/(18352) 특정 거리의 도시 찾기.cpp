#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>

int N, M, K, X;
vector<int> v[300001];
int visited[300001] = { 0, };
vector<int> ans;

void BFS() {
	queue<int> q;
	visited[X] = 1;
	q.push(X);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (visited[node] == K + 1)
			ans.push_back(node);
		if (visited[node] > K + 1)
			break;
		int len = v[node].size();
		FOR(i, 0, len - 1) {
			int next = v[node][i];
			if (visited[next]) continue;
			visited[next] = visited[node] + 1;
			q.push(next);
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K >> X;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	BFS();
	int len = ans.size();
	if (len == 0)
		cout << -1;
	else {
		sort(ans.begin(), ans.end());
		FOR(i, 0, len - 1)
			cout << ans[i] << "\n";
	}

	return 0;
}