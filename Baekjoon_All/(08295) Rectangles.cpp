#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int n, m, p;
	cin >> n >> m >> p;
	int sum = 0;
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			if (2 * (i + j) < p) continue;
			sum += ((n + 1) - i) * ((m + 1) - j);
		}
	}
	cout << sum;

	return 0;
}