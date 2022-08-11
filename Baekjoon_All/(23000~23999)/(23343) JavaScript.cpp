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
	string x, y;
	cin >> x >> y;
	bool f1 = true, f2 = true;
	FOR(i, 0, LEN(x) - 1) {
		if (!(x[i] >= '0' && x[i] <= '9')) {
			f1 = false;
			break;
		}
	}
	FOR(i, 0, LEN(y) - 1) {
		if (!(y[i] >= '0' && y[i] <= '9')) {
			f2 = false;
			break;
		}
	}
	if (!f1 || !f2) {
		cout << "NaN";
	}
	else {
		cout << stoi(x) - stoi(y);
	}

	return 0;
}