#include <iostream>
using namespace std;

int main() {
	int num;
	char X;
	int result;
	cin >> num;
	result = num;
	while (true) {
		cin >> X;
		if (X == '=')
			break;
		cin >> num;
		if (X == '+')
			result += num;
		else if (X == '-')
			result -= num;
		else if (X == '*')
			result *= num;
		else if (X == '/')
			result /= num;
	}
	cout << result;

	return 0;
}