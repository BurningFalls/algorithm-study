#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll num[100001];
ll sum[100001];

int main() {
	FASTIO;
	ll ans = 0;
	int N;
	cin >> N;
	sum[0] = 0;
	FOR(i, 1, N) {
		cin >> num[i];
		sum[i] = sum[i - 1] + num[i];
	}
	FOR(i, 1, N - 1) {
		ans += num[i] * (sum[N] - sum[i]);
	}
	cout << ans;

	return 0;
}