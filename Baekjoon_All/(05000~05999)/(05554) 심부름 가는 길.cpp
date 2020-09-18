#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	int sum;
	cin >> a >> b >> c >> d;
	sum = a + b + c + d;
	cout << sum / 60 << endl;
	cout << sum % 60 << endl;

	return 0;
}