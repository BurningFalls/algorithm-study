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

int N;
vector<vector<int>> Edge(1001, vector<int>());
vector<int> Indegree(1001, 0);
vector<int> ans(1001, 0);

void TS() {
	queue<int> q;
	FOR(i, 1, N) {
		if (Indegree[i] == 0) {
			q.push(i);
			ans[i] = 1;
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int next : Edge[node]) {
			if (--Indegree[next] == 0) {
				ans[next] = ans[node] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	FASTIO;
	int M;
	cin >> N >> M;
	FOR(m, 1, M) {
		int A, B;
		cin >> A >> B;
		Edge[A].push_back(B);
		Indegree[B]++;
	}
	TS();
	FOR(i, 1, N) {
		cout << ans[i] << " ";
	}

	return 0;
}