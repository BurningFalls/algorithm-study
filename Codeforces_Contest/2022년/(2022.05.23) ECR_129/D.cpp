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
#define INF int(2e9)
#define LINF ll(1e18)

int ans = INF;

void DFS(int N, ll X, int cnt) {
	string sx = to_string(X);
	if (LEN(sx) == N) {
		ans = min(ans, cnt);
		return;
	}

	if (cnt + N - LEN(sx) >= ans) return;

	vector<bool> visited(10, 0);
	FOR(i, 0, LEN(sx) - 1) {
		ll t = sx[i] - '0';
		if (t <= 1) continue;
		if (visited[t]) continue;
		visited[t] = 1;
		DFS(N, X * t, cnt + 1);
	}
}

int main() {
	FASTIO;
	int N;
	ll X;
	cin >> N >> X;
	DFS(N, X, 0);

	cout << (ans == INF ? -1 : ans);

	return 0;
}