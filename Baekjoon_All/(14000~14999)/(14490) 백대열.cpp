#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int GCD(int a, int b) {
	for (int i = min(a, b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0)
			return i;
	}
}

int main() {
	string str;
	int loc = 0;
	string str1, str2;
	int num1, num2;
	int gcd;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ':') {
			loc = i;
			break;
		}
	}
	str1 = str.substr(0, loc);
	str2 = str.substr(loc + 1, str.size() - loc - 1);
	num1 = stoi(str1);
	num2 = stoi(str2);
	gcd = GCD(num1, num2);
	cout << num1 / gcd << ":" << num2 / gcd;

	return 0;
}