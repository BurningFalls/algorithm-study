#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n - (n - 1) / 4 - 1; i++)
			cout << 9;
		for (int i = 0; i < (n - 1) / 4 + 1; i++)
			cout << 8;
		cout << "\n";
	}

	return 0;
}