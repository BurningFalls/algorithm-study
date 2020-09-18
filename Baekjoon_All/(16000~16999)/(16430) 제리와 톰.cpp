#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	if (A / B >= 1)
		cout << 0;
	else
		cout << B - A << " " << B;

	return 0;
}