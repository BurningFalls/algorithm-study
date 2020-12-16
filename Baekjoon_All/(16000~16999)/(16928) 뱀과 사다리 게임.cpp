#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101] = { 0, };
int visited[101] = { 0, };

int BFS() {
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node == 100)
			return visited[node] - 1;
		FOR(i, 1, 6) {
			int nn = node + i;
			if (nn > 100) continue;
			if (arr[nn] != 0)
				nn = arr[nn];
			if (visited[nn]) continue;
			visited[nn] = visited[node] + 1;
			q.push(nn);
		}
	}

}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		int x, y;
		cin >> x >> y;
		arr[x] = y;
	}
	FOR(i, 1, M) {
		int u, v;
		cin >> u >> v;
		arr[u] = v;
	}
	cout << BFS();

	return 0;
}