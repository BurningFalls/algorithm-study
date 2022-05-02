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
	cin >> N;
	vector<ll> P(N);
	vector<ll> Ldp(N), Rdp(N);
	vector<ll> max_Ldp(N), max_Rdp(N);
	ll ans = 0;
	FOR(i, 0, N - 1) {
		cin >> P[i];
		ans += P[i];
	}

	Ldp[0] = P[0];
	max_Ldp[0] = Ldp[0];
	FOR(i, 1, N - 1) {
		Ldp[i] = max(P[i], Ldp[i - 1] + P[i]);
		max_Ldp[i] = max(max_Ldp[i - 1], Ldp[i]);
	}
	
	Rdp[N - 1] = P[N - 1];
	max_Rdp[N - 1] = Rdp[N - 1];
	ROF(i, N - 2, 0) {
		Rdp[i] = max(P[i], Rdp[i + 1] + P[i]);
		max_Rdp[i] = max(max_Rdp[i + 1], Rdp[i]);
	}

	ll maxi = max(0LL, max_Ldp[N - 1]);
	FOR(i, 0, N - 2) {
		maxi = max(maxi, max_Ldp[i] + max_Rdp[i + 1]);
	}
	ans += maxi;

	cout << ans;

	return 0;
}