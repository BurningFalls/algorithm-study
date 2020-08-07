#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string str;
	int num;
	int len;
	int sum;
	while (true) {
		cin >> str;
		if (str == "#")
			break;
		len = str.size();
		sum = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] == '-')
				num = 0;
			else if (str[i] == '\\')
				num = 1;
			else if (str[i] == '(')
				num = 2;
			else if (str[i] == '@')
				num = 3;
			else if (str[i] == '?')
				num = 4;
			else if (str[i] == '>')
				num = 5;
			else if (str[i] == '&')
				num = 6;
			else if (str[i] == '%')
				num = 7;
			else if (str[i] == '/')
				num = -1;
			sum += num * int(pow(8, len - 1 - i));
		}
		cout << sum << "\n";
	}

	return 0;
}