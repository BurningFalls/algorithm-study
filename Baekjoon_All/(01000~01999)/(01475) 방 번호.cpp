#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	int arr[10] = { 0, };
	int temp;
	int maximum;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j <= 9; j++) {
			if (s[i] - '0' == j) {
				arr[j]++;
				break;
			}
		}
	}
	if ((arr[6] + arr[9]) % 2 == 0) {
		temp = (arr[6] + arr[9]) / 2;
	}
	else {
		temp = (arr[6] + arr[9]) / 2 + 1;
	}
	arr[6] = 0; arr[9] = 0;
	maximum = *max_element(arr, arr + 10);
	cout << max(maximum, temp) << endl;

	return 0;
}