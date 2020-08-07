#include <iostream>
#include <string>
using namespace std;

bool Check(string s) {
	int len = s.size();
	int num1 = int(s[0]);
	int num2;
	if (num1 >= 65 && num1 <= 90)
		num2 = num1 + 32;
	else
		num2 = num1 - 32;
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			if (s[i + 1] != num1 && s[i + 1] != num2) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	string str;
	while (true) {
		getline(cin, str);
		if (str == "*")
			break;
		if (Check(str))
			cout << "Y\n";
		else
			cout << "N\n";
	}

	return 0;
}