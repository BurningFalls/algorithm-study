#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double a;
	cin >> a;
	cout << fixed << setprecision(6) << sqrt(a) * 4;
	return 0;
}