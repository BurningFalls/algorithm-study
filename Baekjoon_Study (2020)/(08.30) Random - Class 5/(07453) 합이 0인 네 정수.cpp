#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N;
int A[4001], B[4001], C[4001], D[4001];
vector<int> sum_v;

int main() {
	FASTIO;
	ll ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			sum_v.push_back(A[i] + B[j]);
		}
	}
	sort(sum_v.begin(), sum_v.end());
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int temp = C[i] + D[j];
			ll lb, ub;
			lb = lower_bound(sum_v.begin(), sum_v.end(), -temp) - sum_v.begin();
			if (lb == sum_v.size() || temp != -sum_v[lb])
				continue;
			ub = upper_bound(sum_v.begin(), sum_v.end(), -temp) - sum_v.begin();
			ans += ub - lb;
		}
	}
	cout << ans;

	return 0;
}