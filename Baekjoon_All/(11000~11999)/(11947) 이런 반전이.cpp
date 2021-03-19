#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string N;
		cin >> N;
		if (N == "1000000000") {
			cout << 8999999999000000000 << "\n";
			continue;
		}
		int len = N.size();
		ll tmp = 5 * pow(10, len - 1);
		ll n = stoi(N);
		if (n <= tmp - 1) {
			string M = "";
			FOR(i, 0, len - 1) {
				M += (9 - (N[i] - '0')) + '0';
			}
			ll m = stoi(M);
			cout << n * m << "\n";
		}
		else if (n >= tmp) {
			cout << tmp * (tmp - 1) << "\n";
		}
	}

	return 0;
}