#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int main() {
	string s1, s2;
	int arr[2][26] = { 0, };
	int minimum[26];
	int len1;
	int len2;
	int sum = 0;
	cin >> s1;
	cin >> s2;
	len1 = s1.size();
	len2 = s2.size();
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < 26; j++) {
			if (int(s1[i]) - 97 == j) {
				arr[0][j] += 1;
				break;
			}
		}
	}
	for (int i = 0; i < len2; i++) {
		for (int j = 0; j < 26; j++) {
			if (int(s2[i]) - 97 == j) {
				arr[1][j] += 1;
				break;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		minimum[i] = min(arr[0][i], arr[1][i]);
	}
	for (int i = 0; i < 26; i++) {
		arr[0][i] = abs(arr[0][i] - minimum[i]);
		arr[1][i] = abs(arr[1][i] - minimum[i]);
	}
	for (int i = 0; i < 26; i++) {
		sum = sum + arr[0][i] + arr[1][i];
	}
	cout << sum << endl;

	return 0;
}