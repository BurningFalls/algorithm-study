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
	int N, M;
	cin >> N >> M;
	vector<ll> A(N), B(M);
	ll ans = 0;
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	FOR(i, 0, M - 1) {
		cin >> B[i];
	}
	sort(ALL(A), greater<ll>());
	sort(ALL(B));
	FOR(i, 0, min(N, M) - 1) {
		ans += max(0LL, A[i] - B[i]);
	}
	cout << ans;

	return 0;
}