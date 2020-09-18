#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define M 1234567891
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int L;
	string s;
	ll ans = 0;
	int r = 31;
	cin >> L;
	cin >> s;
	FOR(i, 0, s.size() - 1) {
		ll temp = ll(s[i]) - 'a' + 1;
		FOR(j, 1, i) {
			temp = (temp * r) % M;
		}
		ans = (ans + temp) % M;
	}
	cout << ans;

	return 0;
}