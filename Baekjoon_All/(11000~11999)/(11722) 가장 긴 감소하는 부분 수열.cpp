#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N + 1];
	int* dp = new int[N + 1];
	int maximum;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		maximum = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] > arr[i]) {
				maximum = max(maximum, dp[j]);
			}
		}
		dp[i] = maximum + 1;
	}
	cout << *max_element(dp, dp + N + 1);


	return 0;
}