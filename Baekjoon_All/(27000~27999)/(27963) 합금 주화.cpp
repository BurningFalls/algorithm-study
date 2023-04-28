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
	double d1, d2, x;
	cin >> d1 >> d2 >> x;
	double ans = 0;
	if (d1 >= d2) {
		ans = x / (100 * d1) + (100 - x) / (100 * d2);
	}
	else if (d1 < d2) {
		ans = (100 - x) / (100 * d1) + x / (100 * d2);
	}
	ans = 1 / ans;
	cout << fixed << setprecision(6);
	cout << ans;

	return 0;
}