#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int main() {
	string str;
	int sum = 0;
	int temp;
	char arr[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	cin >> str;
	if (str[0] == '0') {
		if (str[1] == 'x') {
			for (int i = 2; i < str.size(); i++) {
				if (int(str[i]) >= 97 && int(str[i]) <= 102) {
					temp = int(str[i]) - 87;
				}
				else {
					temp = str[i] - '0';
				}
				sum += (temp * pow(16, str.size() - i - 1));
			}
		}
		else {
			for (int i = 1; i < str.size(); i++) {
				sum += ((int(str[i]) - '0') * pow(8, str.size() - i - 1));
			}
		}
		cout << sum;
	}
	else {
		cout << str;
	}


	return 0;
}