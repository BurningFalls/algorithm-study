#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define MAX 10 - 1

int main() {
	string a, b;
	cin >> a >> b;
	int x, y;
	FOR(i, 0, MAX) {
		x = a[i] - '0';
		y = b[i] - '0';
		cout << (x & y);
	}
	cout << "\n";
	FOR(i, 0, MAX) {
		x = a[i] - '0';
		y = b[i] - '0';
		cout << (x | y);
	}
	cout << "\n";
	FOR(i, 0, MAX) {
		x = a[i] - '0';
		y = b[i] - '0';
		cout << (x ^ y);
	}
	cout << "\n";
	FOR(i, 0, MAX) {
		x = a[i] - '0';
		cout << (!x);
	}
	cout << "\n";
	FOR(i, 0, MAX) {
		y = b[i] - '0';
		cout << (!y);
	}

	return 0;
}