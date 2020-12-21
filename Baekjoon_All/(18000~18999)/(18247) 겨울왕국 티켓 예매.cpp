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
	int a, b;
	while (T--) {
		cin >> a >> b;
		if (a < 12 || b < 4)
			cout << -1;
		else
			cout << b * 11 + 4;
		cout << "\n";
	}

	return 0;
}