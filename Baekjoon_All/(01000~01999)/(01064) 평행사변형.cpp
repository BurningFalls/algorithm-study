#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

double Calc(pii a, pii b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
	FASTIO;
	double x[3], y[3];
	FOR(i, 0, 2)
		cin >> x[i] >> y[i];
	double dist[3];
	FOR(i, 0, 2)
		dist[i] = Calc({ x[i], y[i] }, { x[(i + 1) % 3], y[(i + 1) % 3] });
	sort(dist, dist + 3);
	if ((y[1] - y[0]) * (x[2] - x[1]) == (y[2] - y[1]) * (x[1] - x[0])) {
		cout << -1;
		return 0;
	}
	cout << fixed << setprecision(10);
	cout << 2 * (dist[2] - dist[0]);

	return 0;
}