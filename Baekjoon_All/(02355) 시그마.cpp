#include <iostream>
using namespace std;

int main() {
	long long int A, B;
	cin >> A >> B;
	if (A <= B)
		cout << (A + B) * (B - A + 1) / 2;
	else
		cout << (A + B) * (A - B + 1) / 2;

	return 0;
}