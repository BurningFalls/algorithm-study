#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int n, m;
	int a, b;
	cin >> n >> m;
	int maximum = m;
	FOR(i, 1, n) {
		cin >> a >> b;
		m = m + a - b;
		if (m < 0) {
			maximum = 0;
			break;
		}
		maximum = max(maximum, m);
	}
	cout << maximum;

	return 0;
}