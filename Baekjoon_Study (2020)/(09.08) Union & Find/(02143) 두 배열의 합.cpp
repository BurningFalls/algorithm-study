#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll A[1001];
ll B[1001];
vector<ll> sum_v;

int main() {
	FASTIO;
	int T;
	int N, M;
	ll ans = 0;
	cin >> T;
	cin >> N;
	FOR(i, 1, N)
		cin >> A[i];
	cin >> M;
	FOR(i, 1, M)
		cin >> B[i];
	FOR(start, 1, N) {
		ll temp = 0;
		FOR(end, start, N) {
			temp += A[end];
			sum_v.push_back(temp);
		}
	}
	sort(sum_v.begin(), sum_v.end());
	FOR(start, 1, M) {
		ll temp = 0;
		FOR(end, start, M) {
			temp += B[end];
			ll lb = lower_bound(sum_v.begin(), sum_v.end(), T - temp) - sum_v.begin();
			ll ub = upper_bound(sum_v.begin(), sum_v.end(), T - temp) - sum_v.begin();
			ans += (ub - lb);
		}
	}
	cout << ans;

	return 0;
}