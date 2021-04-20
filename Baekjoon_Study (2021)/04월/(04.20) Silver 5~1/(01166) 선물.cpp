#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll N, L, W, H;
	cin >> N >> L >> W >> H;
	long double start, end;
	start = 0;
	end = min({ L, W, H });

	FOR(i, 0, 9999) {
		long double mid = (start + end) / 2;
		if (((ll)(L / mid)) * ((ll)(W / mid)) * ((ll)(H / mid)) >= N)
			start = mid;
		else
			end = mid;
	}
	cout << fixed << setprecision(10);
	cout << start;

	return 0;
}