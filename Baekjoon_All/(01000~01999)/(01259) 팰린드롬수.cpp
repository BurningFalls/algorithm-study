#include <iostream>
#include <string>
using namespace std;

bool Check(string s) {
	int len = s.size();
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}

int main() {
	string str;
	while (true) {
		cin >> str;
		if (str == "0")
			break;
		if (Check(str))
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}