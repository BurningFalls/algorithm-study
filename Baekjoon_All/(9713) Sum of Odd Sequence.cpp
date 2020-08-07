#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	int num;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> num;
		cout << int(pow((num + 1) / 2, 2)) << "\n";
	}

	return 0;
}