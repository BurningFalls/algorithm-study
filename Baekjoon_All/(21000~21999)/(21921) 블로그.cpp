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
	ll N, X;
	cin >> N >> X;
	vector<ll> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}

	ll sum = 0;
	FOR(i, 0, X - 1) {
		sum += v[i];
	}
	ll maxi = sum;
	FOR(i, X, N - 1) {
		sum += v[i];
		sum -= v[i - X];
		maxi = max(maxi, sum);
	}

	int cnt = 0;
	sum = 0;
	FOR(i, 0, X - 1) {
		sum += v[i];
	}
	if (sum == maxi) cnt++;
	FOR(i, X, N - 1) {
		sum += v[i];
		sum -= v[i - X];
		if (sum == maxi) cnt++;
	}

	if (maxi == 0) {
		cout << "SAD";
	}
	else {
		cout << maxi << "\n" << cnt;
	}


	return 0;
}