#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int temp;
	int sum = 0;
	cin >> str;
	if (str.size() == 2) {
		temp = str[0] - '0';
		sum += temp;
		temp = str[1] - '0';
		sum += temp;
		cout << sum;
	}
	else if (str.size() == 3) {
		if (str[0] == '1' && str[1] == '0') {
			temp = str[2] - '0';
			cout << 10 + temp;
		}
		else if (str[1] == '1' && str[2] == '0') {
			temp = str[0] - '0';
			cout << 10 + temp;
		}
	}
	else if (str.size() == 4) {
		cout << 20;
	}

	return 0;
}