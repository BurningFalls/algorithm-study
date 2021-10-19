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

int N;
int Price[15][15];
int DP[15][(1 << 15)][10] = { 0, };

int DFS(int node, int vis, int prep) {
	int& ret = DP[node][vis][prep];
	if (ret != 0)
		return ret;
	if (vis == (1 << N) - 1) {
		return ret = 1;
	}
	ret = 1;
	FOR(next, 0, N - 1) {
		if (vis & (1 << next)) continue;
		if (Price[node][next] < prep) continue;
		ret = max(ret, DFS(next, (vis | (1 << next)), Price[node][next]) + 1);
	}
	return ret;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			char x;
			cin >> x;
			Price[i][j] = x - '0';
		}
	}
	cout << DFS(0, 1, 0);

	return 0;
}