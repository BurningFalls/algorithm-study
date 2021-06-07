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
	int A, B, C, AB, BC, CA;
	cin >> T;
	while (T--) {
		cin >> A >> B >> C;
		cin >> AB >> BC >> CA;
		int min_AB = min(A, B);
		int maxi = 0;
		int ans = 0;
		FOR(i, 0, min_AB) {
			ans += i * AB;
			A -= i; B -= i;
			int min_BC = min(B, C);
			FOR(j, 0, min_BC) {
				ans += j * BC;
				B -= j; C -= j;
				int min_CA = min(C, A);
				ans += min_CA * CA;

				maxi = max(ans, maxi);

				ans -= min_CA * CA;
				B += j; C += j;
				ans -= j * BC;
			}
			A += i; B += i;
			ans -= i * AB;
		}
		cout << maxi << "\n";
	}

	return 0;
}