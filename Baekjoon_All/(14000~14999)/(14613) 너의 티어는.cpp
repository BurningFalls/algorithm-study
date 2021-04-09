#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll fact[21];

int main() {
	FASTIO;
	fact[0] = 1;
	fact[1] = 1;
	FOR(i, 2, 20)
		fact[i] = fact[i - 1] * i;
	long double ans[6] = { 0, };
	long double W, L, D;
	cin >> W >> L >> D;
	FOR(w, 0, 20) {
		FOR(l, 0, 20 - w) {
			int d = 20 - w - l;
			long double tmp = powl(W, w) * powl(L, l) * powl(D, d);
			int score = 2000 + 50 * (w - l);
			ll cnt = ((fact[20] / fact[w]) / fact[l]) / fact[d];
			tmp *= cnt;
			if (1000 <= score && score < 1500)
				ans[1] += tmp;
			else if (1500 <= score && score < 2000)
				ans[2] += tmp;
			else if (2000 <= score && score < 2500)
				ans[3] += tmp;
			else if (2500 <= score && score < 3000)
				ans[4] += tmp;
			else if (3000 <= score && score < 3500)
				ans[5] += tmp;
		}
	}
	cout << fixed << setprecision(8);
	FOR(i, 1, 5)
		cout << ans[i] << "\n";


	return 0;
}