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

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<int> t(N, 0);
	vector<int> sum(N + 1, 0);
	FOR(i, 0, N - 1) {
		cin >> t[i];
		if (i >= 1) {
			sum[i] = sum[i - 1] + t[i - 1];
		}
	}
	sum[N] = sum[N - 1] + t[N - 1];
	int maxi = 0;
	FOR(i, 1, M) {
		int p, r, c;
		cin >> p >> r >> c;
		p -= 1, r -= 1;
		int idx = lower_bound(ALL(sum), c % sum[N]) - sum.begin();
		c = (c / sum[N]) * sum[N] + sum[p];
		if (p < idx) {
			c += sum[N];
		}
		if (p < r) {
			c += sum[r] - sum[p];
		}
		else if (r < p) {
			c += sum[N] - sum[p];
			c += sum[r] - sum[0];
		}
		maxi = max(maxi, c);
	}
	cout << maxi;

	return 0;
}