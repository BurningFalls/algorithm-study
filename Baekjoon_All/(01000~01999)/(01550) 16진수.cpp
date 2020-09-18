#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	string str;
	int sum = 0;
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] >= 48 && str[i] <= 57) {
			sum += pow(16, str.size() - i - 1) * (str[i] - 48);
		}
		else if (str[i] >= 65 && str[i] <= 70) {
			sum += pow(16, str.size() - i - 1) * (str[i] - 55);
		}
	}
	cout << sum;

	return 0;
}