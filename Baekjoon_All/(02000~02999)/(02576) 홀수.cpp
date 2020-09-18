#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num;
	int sum = 0;
	int minimum = 0;
	for (int i = 0; i < 7; i++) {
		cin >> num;
		if (num % 2 == 1) {
			sum += num;
			if (minimum == 0)
				minimum = num;
			else
				minimum = min(minimum, num);
		}
	}
	if (sum == 0)
		cout << -1;
	else
		cout << sum << "\n" << minimum;

	return 0;
}