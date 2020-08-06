#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int temp;
	char En;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		temp = str[i];
		if (temp >= 65 && temp <= 90) {
			En = ((temp + 13) - 65) % 26 + 65;
			str[i] = En;
		}
		else if (temp >= 97 && temp <= 122) {
			En = ((temp + 13) - 97) % 26 + 97;
			str[i] = En;
		}
	}
	cout << str;

	return 0;
}