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
	ll N, M, K, X;
	cin >> N >> M >> K >> X;
	vector<ll> score(N + 1);
	vector<ll> cnt(N + 1);
	score[0] = X;
	FOR(i, 1, N) {
		ll num;
		cin >> num;
		score[i] = num + score[i - 1];
	}
	cnt[0] = (score[0] < K);
	FOR(i, 1, N) {
		cnt[i] = (score[i] < K) + cnt[i - 1];
	}
	FOR(m, 1, M) {
		int l, r;
		cin >> l >> r;
		cout << cnt[r - 1] - cnt[l - 1] << "\n";
	}
	return 0;
}