#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int T;
	double a, b, c, d, e;
	double result;
	cin >> T;
	for (int A = 0; A < T; A++) {
		cin >> a >> b >> c >> d >> e;
		result = 350.34 * a + 230.90 * b + 190.55 * c + 125.30 * d + 180.90 * e;
		cout << fixed << setprecision(2) << "$" << result << "\n";
	}

	return 0;
}