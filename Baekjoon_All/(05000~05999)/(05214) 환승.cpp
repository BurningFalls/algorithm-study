#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K, M;
vector<int> v[101001];
int visited[101001] = { 0, };

int BFS() {
	queue<int> q;
	visited[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node == N)
			return visited[node];
		int len = v[node].size();
		FOR(i, 0, len - 1) {
			int nn = v[node][i];
			if (visited[nn]) continue;
			q.push(nn);
			visited[nn] = visited[node];
			if (nn <= 100000)
				visited[nn] += 1;
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> N >> K >> M;
	FOR(i, 1, M) {
		FOR(j, 1, K) {
			int x;
			cin >> x;
			v[x].push_back(100000 + i);
			v[100000 + i].push_back(x);
		}
	}
	cout << BFS();

	return 0;
}