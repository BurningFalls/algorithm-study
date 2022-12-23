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
	int Q;
	cin >> Q;
	ll mini = -1000000000000000001;
	ll maxi = 1000000000000000001;
	bool flag = true;
	int idx = 0;
	int pidx = 0;
	FOR(q, 1, Q) {
		ll x;
		string y;
		cin >> x >> y;
		if (y == "^") {
			mini = max(mini, x);
		}
		else if (y == "v") {
			maxi = min(maxi, x);
		}
		if (pidx == 0 && mini + 1 >= maxi) {
			flag = false;
			pidx = q;
		}
		if (idx == 0 && pidx == 0 && mini + 2 == maxi) {
			idx = q;
		}
	}
	if (!flag) {
		cout << "Paradox!\n";
		cout << pidx;
	}
	else if (flag) {
		if (idx == 0) {
			cout << "Hmm...";
		}
		else {
			cout << "I got it!\n";
			cout << idx;
		}
	}

	return 0;
}