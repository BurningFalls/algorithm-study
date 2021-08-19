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
		cin >> a >> b >> c;
		int diff = abs(a - b);
		int size = diff * 2;
		if (a > size || b > size || c > size)
			cout << -1;
		else
			cout << ((c - diff > 0) ? c - diff : c + diff);
		cout << "\n";
	}


	return 0;
}