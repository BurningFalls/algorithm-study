#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll a, b;
	cin >> a >> b;
	if (a == 1)
		cout << 8 * b;
	else if (a == 2) {
		if (b % 2 == 0)
			cout << 4 * b + 1;
		else if (b % 2 == 1)
			cout << 4 * b + 3;
	}
	else if (a == 3) {
		cout << 4 * b + 2;
	}
	else if (a == 4) {
		if (b % 2 == 0)
			cout << 4 * b + 3;
		else if (b % 2 == 1)
			cout << 4 * b + 1;
	}
	else if (a == 5) {
		cout << 8 * b + 4;
	}

	return 0;
}