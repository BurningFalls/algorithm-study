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

ll island[123457];
vvi Edge(123457, vi());

ll DFS(int node, int prev) {
	ll sum = island[node];
	for (int next : Edge[node]) {
		if (next == prev) continue;
		sum += DFS(next, node);
	}
	return max(0LL, sum);
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	island[1] = 0;
	FOR(i, 2, N) {
		char t;
		ll a;
		int p;
		cin >> t >> a >> p;
		Edge[p].push_back(i);
		if (t == 'S') {
			island[i] = a;
		}
		else if (t == 'W') {
			island[i] = -a;
		}
	}
	cout << DFS(1, 0);

	return 0;
}