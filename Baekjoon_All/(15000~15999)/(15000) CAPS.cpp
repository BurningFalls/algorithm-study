#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	char X;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		X = int(str[i]) - 32;
		cout << X;
	}

	return 0;
}