#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
vector<int> v[300001];
int visited[300001] = { 0, };
int S, E;

int BFS() {
	queue<int> q;
	q.push(S);
	visited[S] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node != N && !visited[node + 1]) {
			visited[node + 1] = visited[node] + 1;
			if (node + 1 == E)
				return visited[node + 1];
			q.push(node + 1);
		}
		if (node != 1 && !visited[node - 1]) {
			visited[node - 1] = visited[node] + 1;
			if (node - 1 == E)
				return visited[node - 1];
			q.push(node - 1);
		}
		for (int next : v[node]) {
			if (visited[next]) continue;
			visited[next] = visited[node] + 1;
			if (next == E)
				return visited[next];
			q.push(next);
		}
	}
}

int main() {
	FASTIO;
	ll M;
	cin >> N >> M;
	cin >> S >> E;
	FOR(i, 1, M) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cout << BFS() - 1;


	return 0;
}