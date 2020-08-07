#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int len1, len2;
	int max = 0;
	cin >> s1;
	cin >> s2;
	len1 = s1.size();
	len2 = s2.size();
	int** dp = new int* [len1 + 1];
	for (int i = 0; i <= len1; i++) {
		dp[i] = new int[len2 + 1];
	}
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (max < dp[i][j]) {
				max = dp[i][j];
			}
		}
	}

	cout << max << endl;


	return 0;
}