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
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<int> v(M);
		FOR(i, 0, M - 1) {
			cin >> v[i];
		}
		vector<ll> tmp;
		sort(ALL(v));
		FOR(i, 1, M - 1) {
			tmp.push_back(v[i] - v[i - 1] - 1);
		}
		tmp.push_back(v[0] - 1 + N - v[M - 1]);
		sort(ALL(tmp), greater<ll>());

		ll ans = 0;
		ll minus = 0;
		FOR(i, 0, LEN(tmp) - 1) {
			tmp[i] -= minus;
			if (1 <= tmp[i] && tmp[i] <= 2) {
				ans += 1;
				minus += 2;
			}
			else if (tmp[i] >= 3) {
				ans += tmp[i] - 1;
				minus += 4;
			}
		}
		cout << N - ans << "\n";
	}

	return 0;
}