#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

bool Is_prime(int num) {
	if (num == 1 || num == 2) {
		return true;
	}
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	string s;
	int sum = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (int(s[i]) >= 65 && int(s[i]) <= 90) {
			sum += (int(s[i]) - 38);
		}
		else if (int(s[i]) >= 97 && int(s[i]) <= 122) {
			sum += (int(s[i]) - 96);
		}
	}
	if (Is_prime(sum)) {
		cout << "It is a prime word." << endl;
	}
	else if (!Is_prime(sum)) {
		cout << "It is not a prime word." << endl;
	}

	return 0;
}