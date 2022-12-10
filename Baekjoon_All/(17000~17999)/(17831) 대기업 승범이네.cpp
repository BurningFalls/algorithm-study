#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 200001

int N;
vector<vector<int>> Edge(MAX, vector<int>());
vector<ll> A(MAX);
vector<vector<ll>> dp(MAX, vector<ll>(2, -1));

ll DFS(int node, int idx) {
	ll& ret = dp[node][idx];
	if (ret != -1) {
		return ret;
	}

	ll sum = 0;
	for (int next : Edge[node]) {
		sum += max(DFS(next, 0), DFS(next, 1));
	}
	if (idx == 0) {
		ret = sum;
	}
	else if (idx == 1) {
		for (int next : Edge[node]) {
			ll tmp1 = DFS(next, 0);
			ll tmp2 = DFS(next, 1);
			ret = max(ret, sum - max(tmp1, tmp2) + tmp1 + A[node] * A[next]);
		}
	}

	return ret;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(a, 2, N) {
		int b;
		cin >> b;
		Edge[b].push_back(a);
	}
	FOR(i, 1, N) {
		cin >> A[i];
	}

	cout << max(DFS(1, 0), DFS(1, 1));

	return 0;
}