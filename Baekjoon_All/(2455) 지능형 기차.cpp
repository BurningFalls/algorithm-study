#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	int sum = 0;
	int maximum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a >> b;
		sum -= a;
		sum += b;
		maximum = max(maximum, sum);
	}
	cout << maximum;

	return 0;
}