#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double H, P;
	cout << fixed << setprecision(2);
	while (cin >> H >> P) {
		cout << H / P << "\n";
	}

	return 0;
}