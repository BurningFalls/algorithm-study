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
	int idx = 1;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << "Case " << idx << ":\n";
		FOR(i, 1, n / 2) {
			int a, b;
			a = i;
			b = n - i;
			if (b > 6) continue;
			cout << "(";
			cout << a;
			cout << ",";
			cout << b;
			cout << ")\n";
		}
		idx++;
	}

	return 0;
}