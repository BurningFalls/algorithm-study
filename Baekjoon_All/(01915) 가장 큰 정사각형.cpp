#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	char** arr = new char* [n + 1];
	int** dp = new int* [n + 1];
	int maximum = 0;

	for (int i = 0; i <= n; i++) {
		arr[i] = new char[m + 1];
		dp[i] = new int[m + 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		if (arr[1][i] == '1') {
			dp[1][i] = 1;
		}
		else if (arr[1][i] == '0') {
			dp[1][i] = 0;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i][1] == '1') {
			dp[i][1] = 1;
		}
		else if (arr[i][1] == '0') {
			dp[i][1] = 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (arr[i][j] == '1') {
				if (dp[i - 1][j - 1] <= dp[i - 1][j] && dp[i - 1][j - 1] <= dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
				}
			}
			else if (arr[i][j] == '0') {
				dp[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] > maximum) {
				maximum = dp[i][j];
			}
		}
	}
	cout << maximum * maximum << endl;


	return 0;
}