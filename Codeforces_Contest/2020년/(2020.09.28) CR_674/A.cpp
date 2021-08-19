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
		int n, x;
		cin >> n >> x;
		if (n == 1 || n == 2)
			cout << 1;
		else {
			cout << 2 + (n - 3) / x;
		}
		cout << "\n";
	}

	return 0;
}