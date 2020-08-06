#include <iostream>
#include <string>
using namespace std;

bool flag1;
bool flag2;

int Check(string str) {
	int len = str.size();
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			for (int j = 0; j < len - 2 * i - 2; j++) {
				if (str[i + j] != str[len - i - 2 - j]) {
					flag1 = false;
				}
				if (str[i + 1 + j] != str[len - i - 1 - j]) {
					flag2 = false;
				}
			}
			if (flag1 || flag2)
				return 1;
			else
				return 2;
		}
	}
	return 0;
}

int main() {
	int T;
	string str;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> str;
		flag1 = true;
		flag2 = true;
		cout << Check(str) << "\n";
	}

	return 0;
}