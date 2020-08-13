#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		if (n >= 31) {
			cout << "YES\n";
			if (n == 36)
				cout << 5 << " " << 6 << " " << 10 << " " << 15 << "\n";
			else if (n == 40)
				cout << 6 << " " << 9 << " " << 10 << " " << 15 << "\n";
			else if (n == 44)
				cout << 6 << " " << 7 << " " << 10 << " " << 21 << "\n";
			else
				cout << 6 << " " << 10 << " " << 14 << " " << n - 30 << "\n";
		}
		else
			cout << "NO\n";
	}

	return 0;
}