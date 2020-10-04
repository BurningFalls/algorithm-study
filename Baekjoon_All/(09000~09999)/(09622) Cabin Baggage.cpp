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
	int cnt = 0;
	cin >> T;
	while (T--) {
		double a, b, c, d;
		cin >> a >> b >> c >> d;
		if (((a <= 56 && b <= 45 && c <= 25) || (a + b + c <= 125)) && (d <= 7)) {
			cout << 1;
			cnt++;
		}
		else
			cout << 0;
		cout << "\n";
	}
	cout << cnt;

	return 0;
}