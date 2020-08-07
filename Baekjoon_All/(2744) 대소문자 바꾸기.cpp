#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	char X;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 65 && str[i] <= 90)
			X = str[i] + 32;
		else if (str[i] >= 97 && str[i] <= 122)
			X = str[i] - 32;
		cout << X;
	}

	return 0;
}