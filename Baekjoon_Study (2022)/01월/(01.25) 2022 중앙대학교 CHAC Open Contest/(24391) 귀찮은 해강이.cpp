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

vector<vector<int>> Edge(100001, vector<int>());
vector<int> group(100001, 0);

void BFS(int start, int idx) {
	queue<int> q;
	group[start] = idx;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int next : Edge[node]) {
			if (group[next]) continue;
			group[next] = idx;
			q.push(next);
		}
	}
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	FOR(m, 1, M) {
		int a, b;
		cin >> a >> b;
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	int idx = 0;
	FOR(i, 1, N) {
		if (group[i]) continue;
		idx++;
		BFS(i, idx);
	}
	int cnt = 0;
	FOR(i, 0, N - 2) {
		cnt += (group[A[i]] != group[A[i + 1]]);
	}
	cout << cnt;

	return 0;
}