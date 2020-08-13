#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, S, M;
	cin >> N >> S >> M;
	int* arr = new int[N + 1];
	int** dp = new int* [N + 1];
	int maximum = -1;
	for (int i = 0; i <= N; i++) {
		dp[i] = new int[M + 1];
	}
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][S] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j + arr[i] <= M && dp[i - 1][j + arr[i]] == 1) {
				dp[i][j] = 1;
			}
			if (j - arr[i] >= 0 && dp[i - 1][j - arr[i]] == 1) {
				dp[i][j] = 1;
			}
		}
	}
	for (int i = M; i >= 0; i--) {
		if (dp[N][i] == 1 && maximum < i) {
			maximum = i;
		}
	}
	cout << maximum << endl;



	return 0;
}