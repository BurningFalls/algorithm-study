#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		int maximum = 1;
		int wh[200001];
		memset(wh, -1, sizeof(wh));
		string s;
		char X;
		cin >> n;
		cin >> s;
		X = s[0];
		wh[0] = 1;
		int z = 1;
		while (true) {
			for (int i = 1; i < n; i++) {
				if (s[i] != X) {
					wh[i] = z;
					X = s[i];
				}
				maximum = max(maximum, wh[i]);
			}
			z++;
		}
		cout << maximum << "\n";
		for (int i = 0; i < n; i++) {
			cout << wh[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}