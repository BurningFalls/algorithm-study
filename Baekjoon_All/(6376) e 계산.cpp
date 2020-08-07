#include <iostream>
#include <iomanip>
using namespace std;

double fac(int num) {
	if (num == 0) {
		return 1;
	}
	int ans = 1;
	for (int i = 1; i <= num; i++) {
		ans *= i;
	}
	return ans;
}

int main() {
	double e;
	cout << "n e" << endl;
	cout << "- -----------" << endl;
	for (int n = 0; n <= 9; n++) {
		e = 0;
		for (int i = 0; i <= n; i++) {
			e += 1 / fac(i);
		}
		if (n >= 3) {
			cout << fixed << setprecision(9);
		}
		cout << n << " " << e << endl;
	}

	return 0;
}