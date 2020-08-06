#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	int W[51];
	int visited[1000] = { 0, };
	int minimum, maximum;
	int k_max, k;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		k_max = 0;
		minimum = 51, maximum = 0;
		for (int i = 0; i < 1000; i++)
			visited[i] = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> W[i];
			minimum = min(minimum, W[i]);
			maximum = max(maximum, W[i]);
			visited[W[i]] += 1;
		}
		for (int x = minimum * 2; x <= maximum * 2; x++) {
			k = 0;
			for (int i = 1; i <= x / 2; i++) {
				if (i == x - i)
					k += visited[i] / 2;
				else
					k += min(visited[i], visited[x - i]);
			}
			k_max = max(k, k_max);
		}
		cout << k_max << "\n";
	}

	return 0;
}