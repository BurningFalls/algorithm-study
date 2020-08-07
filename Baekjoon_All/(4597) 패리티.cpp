#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int len;
	char X;
	int one_cnt;
	while (true) {
		cin >> str;
		if (str == "#")
			break;
		one_cnt = 0;
		len = str.size();
		X = str[len - 1];
		for (int i = 0; i < len - 1; i++) {
			if (str[i] == '1')
				one_cnt++;
		}
		for (int i = 0; i < len - 1; i++)
			cout << str[i];
		if (one_cnt % 2 == 0) {
			if (X == 'e')
				cout << "0\n";
			else if (X == 'o')
				cout << "1\n";
		}
		else if (one_cnt % 2 == 1) {
			if (X == 'e')
				cout << "1\n";
			else if (X == 'o')
				cout << "0\n";
		}
	}

	return 0;
}