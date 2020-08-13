#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int T;
	double num;
	string str;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> num;
		getline(cin, str);
		for (int i = 1; i < str.size(); i += 2) {
			if (str[i] == '@')
				num *= 3;
			else if (str[i] == '%')
				num += 5;
			else if (str[i] == '#')
				num -= 7;
		}
		cout << fixed << setprecision(2);
		cout << num << endl;
	}

	return 0;
}