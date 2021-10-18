#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vi indegree(N + 1, 0);
	vvi Edge(N + 1, vi());
	FOR(i, 1, M) {
		int A, B;
		cin >> A >> B;
		indegree[B]++;
		Edge[A].push_back(B);
	}
	PQ<int> pq;
	vector<int> ans;
	FOR(i, 1, N) {
		if (indegree[i] == 0) {
			pq.push(-i);
		}
	}
	while (!pq.empty()) {
		int node = -pq.top();
		pq.pop();
		ans.push_back(node);
		for (int next : Edge[node]) {
			if (--indegree[next] == 0) {
				pq.push(-next);
			}
		}
	}
	if (LEN(ans) != N) {
		cout << -1;
	}
	else {
		for (int x : ans)
			cout << x << " ";
	}

	return 0;
}