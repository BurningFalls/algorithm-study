#include <iostream>
using namespace std;

int main() {
	int e, f, c;
	int bottle;
	int temp;
	int sum = 0;
	cin >> e >> f >> c;
	bottle = e + f;
	while (bottle >= c) {
		temp = bottle / c;
		sum += temp;
		bottle = bottle - temp * c + temp;
	}
	cout << sum;

	return 0;
}