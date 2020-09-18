#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

double x[10002];
double y[10002];

int main() {
	FASTIO;
	int N;
	long double sum = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> x[i] >> y[i];
	}
	x[N + 1] = x[1];
	y[N + 1] = y[1];
	FOR(i, 1, N) {
		sum += x[i] * y[i + 1] / 2 - x[i + 1] * y[i] / 2;
	}
	cout << fixed << setprecision(1) << fabs(sum);

	return 0;
}