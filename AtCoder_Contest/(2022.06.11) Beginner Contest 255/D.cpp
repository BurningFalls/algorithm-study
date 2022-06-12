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
	ll N, Q;
	cin >> N >> Q;
	vector<ll> A(N);
	vector<ll> sum(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	sort(ALL(A));
	sum[0] = A[0];
	FOR(i, 1, N - 1) {
		sum[i] = sum[i - 1] + A[i];
	}
	FOR(i, 1, Q) {
		ll X;
		cin >> X;
		if (X <= A[0]) {
			cout << sum[N - 1] - X * N;
		}
		else if (X > A[N - 1]) {
			cout << X * N - sum[N - 1];
		}
		else {
			int lb = lower_bound(ALL(A), X) - A.begin();
			cout << (X * lb - sum[lb - 1]) + (sum[N - 1] - sum[lb - 1] - X * (N - lb));
		}
		cout << "\n";
	}

	return 0;
}