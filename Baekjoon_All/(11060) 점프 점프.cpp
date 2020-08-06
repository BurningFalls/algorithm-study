#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N + 1];
	int* dp = new int[N + 1];
	int minimum;
	int flag;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= N; i++) {
		dp[i] = -1;
	}
	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		flag = false;
		minimum = -2;
		for (int j = 1; j < i; j++) {
			if ((i - j) <= arr[j] && dp[j] != -1) {
				if (flag == false) {
					minimum = dp[j];
					flag = true;
				}
				else {
					minimum = min(minimum, dp[j]);
				}
			}
		}
		dp[i] = minimum + 1;
	}
	if (dp[N] == -1) {
		cout << "-1" << endl;
	}
	else if (N != 1 && arr[1] == 0) {
		cout << "-1" << endl;
	}
	else {
		cout << dp[N] << endl;
	}

	return 0;
}