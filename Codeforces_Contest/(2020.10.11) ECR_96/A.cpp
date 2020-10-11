#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int a, b, c;

bool func(int n) {
	for (int i = 0; 7 * i <= n; i++) {
		for (int j = 0; 5 * j + 7 * i <= n; j++) {
			int temp = n - (5 * j + 7 * i);
			if (temp % 3 == 0) {
				a = temp / 3;
				b = j;
				c = i;
				return true;
			}
		}
	}
	return false;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (func(n))
			cout << a << " " << b << " " << c;
		else
			cout << -1;
		cout << "\n";
	}

	return 0;
}