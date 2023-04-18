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
	string v;
	cin >> v;
	int uc = 0, dp = 0;
	FOR(i, 0, LEN(v) - 1) {
		if (v[i] == 'U' || v[i] == 'C') {
			uc++;
		}
		else if (v[i] == 'D' || v[i] == 'P') {
			dp++;
		}
	}
	string ans = "";
	if (dp % 2 == 0) {
		if (uc > dp / 2) {
			ans += 'U';
		}
	}
	else if (dp % 2 == 1) {
		if (uc > dp / 2 + 1) {
			ans += 'U';
		}
	}

	if (dp != 0) {
		ans += "DP";
	}

	if (ans.empty()) {
		ans += 'C';
	}

	cout << ans;

	return 0;
}