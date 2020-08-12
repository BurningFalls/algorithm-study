#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int r, g, b, w;
		int cnt = 0;
		cin >> r >> g >> b >> w;
		if (r % 2 == 0)
			cnt++;
		if (g % 2 == 0)
			cnt++;
		if (b % 2 == 0)
			cnt++;
		if (w % 2 == 0) {
			if (cnt == 3)
				cout << "YES";
			else if (cnt == 2)
				cout << "YES";
			else if (cnt == 1)
				cout << "NO";
			else if (cnt == 0)
				cout << "YES";
		}
		else if (w % 2 == 1) {
			if (cnt == 3)
				cout << "YES";
			else if (cnt == 2)
				cout << "NO";
			else if (cnt == 1) {
				if (r == 0 || g == 0 || b == 0)
					cout << "NO";
				else
					cout << "YES";
			}
			else if (cnt == 0)
				cout << "YES";
		}
		cout << "\n";
	}

	return 0;
}