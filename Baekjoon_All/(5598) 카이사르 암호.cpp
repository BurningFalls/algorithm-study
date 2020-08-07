#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	char A;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] - 3 < 65) {
			A = str[i] + 23;
			cout << A;
		}
		else {
			A = str[i] - 3;
			cout << A;
		}
	}


	return 0;
}