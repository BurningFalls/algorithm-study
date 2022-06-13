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
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	vector<ll> P(N + 1);
	vector<ll> sum(N + 1, 0);
	FOR(i, 1, N) {
		cin >> P[i];
	}
	sort(P.begin() + 1, P.end(), greater<ll>());
	FOR(i, 1, N) {
		sum[i] = sum[i - 1] + P[i];
	}
	FOR(q, 1, Q) {
		int x, y;
		cin >> x >> y;
		cout << sum[x] - sum[x - y] << "\n";
	}

	return 0;
}