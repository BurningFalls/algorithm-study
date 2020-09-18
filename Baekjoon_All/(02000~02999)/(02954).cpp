#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int len;
	getline(cin, str);
	len = str.size();
	for (int i = 0; i < len - 2; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			str[i + 1] = 'X';
			str[i + 2] = 'X';
		}
	}
	for (int i = 0; i < len; i++) {
		if (str[i] == 'X') continue;
		cout << str[i];
	}

	return 0;
}