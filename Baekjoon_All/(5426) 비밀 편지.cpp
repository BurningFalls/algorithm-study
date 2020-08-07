#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int T;
	string str;
	int len;
	char map[101][101];
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> str;
		len = str.size();
		for (int i = 0; i < sqrt(len); i++) {
			for (int j = sqrt(len) - 1; j >= 0; j--) {
				map[j][i] = str[i * sqrt(len) + (sqrt(len) - 1 - j)];
			}
		}
		for (int i = 0; i < sqrt(len); i++) {
			for (int j = 0; j < sqrt(len); j++) {
				cout << map[i][j];
			}
		}
		cout << "\n";
	}

	return 0;
}