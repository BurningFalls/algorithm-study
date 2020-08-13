#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	vector<char> v1;
	vector<char> v2;
	int count = 1;

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
			else if (s1[i - 1] != s2[j - 1]) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (count == dp[i][j]) {
				count++;
				v1.push_back(s1[i - 1]);
				if (j == len2) {
					i = len1;
				}
			}
		}
	}
	count = 1;
	for (int i = 1; i <= len2; i++) {
		for (int j = 1; j <= len1; j++) {
			if (count == dp[j][i]) {
				count++;
				v2.push_back(s1[j - 1]);
				if (j == len1) {
					i = len2;
				}
			}
		}
	}

	cout << dp[len1][len2] << endl;
	if (dp[len1][len2] != 0) {
		if (v1.size() > v2.size()) {
			for (int i = 0; i < v1.size(); i++) {
				cout << v1[i];
			}
		}
		else {
			for (int i = 0; i < v2.size(); i++) {
				cout << v2[i];
			}
		}
	}


	return 0;
}