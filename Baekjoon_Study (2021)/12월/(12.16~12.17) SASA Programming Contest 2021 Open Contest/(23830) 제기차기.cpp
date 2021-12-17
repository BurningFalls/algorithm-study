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

int main() {
	FASTIO;
	int N;
	ll p, q, r, S;
	cin >> N;
	vector<ll> A(N);
	ll sum = 0;
	FOR(i, 0, N - 1) {
		cin >> A[i];
		sum += A[i];
	}
	cin >> p >> q >> r >> S;
	sort(ALL(A));
	ll left = 1, right = A[N - 1] + 1;
	ll ans = LINF;
	while (left <= right) {
		ll mid = (left + right) / 2;
		int lb = lower_bound(ALL(A), mid) - A.begin();
		int ub = upper_bound(ALL(A), mid + r) - A.begin();
		ll lcnt = lb;
		ll rcnt = N - ub;
		ll nsum = sum - p * rcnt + q * lcnt;
		if (nsum < S) {
			left = mid + 1;
		}
		else if (nsum >= S) {
			ans = min(ans, mid);
			right = mid - 1;
		}
	}
	cout << (ans == LINF ? -1 : ans);

	return 0;
}