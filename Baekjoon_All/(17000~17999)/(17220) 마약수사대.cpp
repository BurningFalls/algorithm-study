#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int N, M;
vector<vector<int>> Edge(26, vector<int>());
vector<int> indegree(26, 0);
queue<int> q;
vector<int> check(26, 0);

void TP() {
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		check[node] = 1;
		for (int next : Edge[node]) {
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		char x, y;
		cin >> x >> y;
		int a = x - 'A';
		int b = y - 'A';
		Edge[a].push_back(b);
		indegree[b]++;
	}
	int k;
	cin >> k;
	FOR(i, 1, k) {
		char c;
		cin >> c;
		q.push(c - 'A');
	}

	set<int> parent;
	FOR(i, 0, N - 1) {
		if (indegree[i] == 0) {
			parent.insert(i);
		}
	}
	TP();

	int cnt = 0;
	FOR(i, 0, N - 1) {
		if (!parent.count(i) && check[i] == 0) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}