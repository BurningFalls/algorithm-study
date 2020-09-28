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
		int n, m;
		cin >> n >> m;
		int a, b, c, d;
		bool flag = false;
		FOR(i, 1, n) {
			cin >> a >> b;
			cin >> c >> d;
			if (b == c)
				flag = true;
		}
		if (m % 2 == 1)
			cout << "NO";
		else {
			if (flag)
				cout << "YES";
			else
				cout << "NO";
		}
		cout << "\n";
	}

	return 0;
}