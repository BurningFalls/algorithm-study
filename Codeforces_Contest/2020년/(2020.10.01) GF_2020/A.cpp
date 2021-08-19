#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int a[101], b[101], c[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		FOR(i, 1, n)
			cin >> a[i];
		FOR(i, 1, n)
			cin >> b[i];
		FOR(i, 1, n)
			cin >> c[i];
		cout << a[1] << " ";
		int past = a[1];
		FOR(i, 2, n - 1) {
			if (a[i] != past) {
				cout << a[i] << " ";
				past = a[i];
			}
			else if (b[i] != past) {
				cout << b[i] << " ";
				past = b[i];
			}
			else if (c[i] != past) {
				cout << c[i] << " ";
				past = c[i];
			}
		}
		if (a[n] != past && a[n] != a[1])
			cout << a[n];
		else if (b[n] != past && b[n] != a[1])
			cout << b[n];
		else if (c[n] != past && c[n] != a[1])
			cout << c[n];
		cout << "\n";
	}

	return 0;
}