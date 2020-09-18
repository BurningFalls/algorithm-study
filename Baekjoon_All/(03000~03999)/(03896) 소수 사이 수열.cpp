#include <iostream>
#include <math.h>
using namespace std;

int Check(int n) {
	if (n == 2)
		return true;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	int T;
	int k;
	int left_prime;
	int right_prime;
	int i;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> k;
		if (Check(k))
			cout << "0" << "\n";
		else {
			i = 1;
			while (true) {
				if (Check(k - i)) {
					left_prime = k - i;
					break;
				}
				i++;
			}
			i = 1;
			while (true) {
				if (Check(k + i)) {
					right_prime = k + i;
					break;
				}
				i++;
			}
			cout << right_prime - left_prime << "\n";
		}
	}

	return 0;
}