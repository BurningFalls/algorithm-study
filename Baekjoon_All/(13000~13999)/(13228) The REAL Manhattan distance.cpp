#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		int d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		cout << (f + c) + abs(a - d) + abs(b - e) << "\n";
	}

	return 0;
}