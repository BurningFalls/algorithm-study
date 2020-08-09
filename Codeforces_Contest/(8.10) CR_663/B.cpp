#include <bits/stdc++.h>
using namespace std;

char arr[102][102];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m;
		int cnt = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
				if (j == m && arr[i][j] == 'R')
					cnt++;
				if (i == n && arr[i][j] == 'D')
					cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}