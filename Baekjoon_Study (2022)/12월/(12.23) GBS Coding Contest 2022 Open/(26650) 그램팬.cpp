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
	string s;
	cin >> s;
	s += 'A';
	char x = 'A';
	ll ans = 0;
	ll acnt = 0, zcnt = 0;
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == x || s[i] == x + 1) {
			if (s[i] == 'A') acnt++;
			if (s[i] == 'Z') zcnt++;
			x = s[i];
		}
		else {
			ans += acnt * zcnt;
			acnt = (s[i] == 'A');
			zcnt = 0;
			x = 'A';
		}
	}
	cout << ans;

	return 0;
}