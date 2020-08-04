#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int l, r;
		cin >> l >> r;
		if (l * 2 <= r)
			cout << l << " " << 2 * l << "\n";
		else
			cout << -1 << " " << -1 << "\n";
	}

	return 0;
}