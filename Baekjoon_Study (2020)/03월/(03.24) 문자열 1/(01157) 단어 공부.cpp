#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	int len;
	cin >> S;
	len = S.size();
	int arr[26] = { 0, };
	for (int i = 0; i < len; i++) {
		if (S[i] >= 65 && S[i] <= 90) {
			arr[S[i] - 65]++;
		}
		else if (S[i] >= 97 && S[i] <= 122) {
			arr[S[i] - 97]++;
		}
	}

	int max = arr[0];
	int location = 0;
	int count = 0;
	for (int i = 1; i < 26; i++) {
		if (max < arr[i]) {
			max = arr[i];
			location = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] == max) {
			count++;
		}
	}
	if (count > 1) {
		cout << "?" << endl;
	}
	else if (count == 1) {
		cout << char(location + 65) << endl;
	}

	return 0;
}