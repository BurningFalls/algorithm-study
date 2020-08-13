#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double PI = 3.14159265358979;
	double R;
	cin >> R;
	cout << fixed;
	cout << setprecision(6);
	cout << double(PI * R * R) << endl;
	cout << 2 * R * R << endl;

	return 0;
}