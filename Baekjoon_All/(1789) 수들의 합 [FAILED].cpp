#include <iostream>
using namespace std;

int main() {
	long long int S;
	int i = 1;
	int sum = 0;
	cin >> S;
	while (true) {
		sum += i;
		if (sum > S)
			break;
		i++;
	}
	cout << i - 1;

	return 0;
}