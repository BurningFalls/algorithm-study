#include <iostream>
#include <string>
using namespace std;

int main() {
	int K;
	string str;
	int len;
	char arr[11][21];
	cin >> K;
	cin >> str;
	len = str.size();
	for (int i = 0; i < len / K; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < K; j++) {
				arr[i][j] = str[i * K + j];
			}
		}
		else if (i % 2 == 1) {
			for (int j = 0; j < K; j++) {
				arr[i][K - 1 - j] = str[i * K + j];
			}
		}
	}
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < len / K; j++) {
			cout << arr[j][i];
		}
	}

	return 0;
}