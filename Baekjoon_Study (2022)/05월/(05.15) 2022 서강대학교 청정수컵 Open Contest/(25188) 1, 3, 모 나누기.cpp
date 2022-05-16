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
	vector<ll> A(N);
	vector<ll> Sum(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
		if (i == 0) {
			Sum[0] = A[0];
		}
		else {
			Sum[i] = Sum[i - 1] + A[i];
		}
	}

	vector<ll> Ldp(N), max_Ldp(N);
	vector<ll> Rdp(N), max_Rdp(N);

	ll ans = max(0LL, Sum[N - 1]);
	FOR(i, 1, N - 1) {
		Ldp[i] = A[i];
		max_Ldp[i] = Ldp[i];
		FOR(j, i + 1, N - 1) {
			Ldp[j] = max(Ldp[j - 1] + A[j], A[j]);
			max_Ldp[j] = max(max_Ldp[j - 1], Ldp[j]);
		}
		Rdp[N - 1] = A[N - 1];
		max_Rdp[N - 1] = Rdp[N - 1];
		ROF(j, N - 2, i) {
			Rdp[j] = max(Rdp[j + 1] + A[j], A[j]);
			max_Rdp[j] = max(max_Rdp[j + 1], Rdp[j]);
		}
		ll maxi = max(0LL, max_Rdp[i]);
		FOR(j, i, N - 2) {
			maxi = max(maxi, max_Ldp[j] + max_Rdp[j + 1]);
		}
		ans = max(ans, maxi + max(0LL, Sum[i - 1]));
	}
	cout << ans;

	return 0;
}