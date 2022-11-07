#include <bits/stdc++.h>
using namespace std;

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
	vector<double> p(10);
	FOR(i, 0, 9) {
		cin >> p[i];
	}
	sort(ALL(p), greater<double>());
	double ans = 1;
	FOR(i, 0, 8) {
		ans *= p[i] / (i + 1);
	}
	cout << fixed << setprecision(6);
	cout << ans * 1000000000;

	return 0;
}