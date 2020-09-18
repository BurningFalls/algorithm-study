#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	long long int A, B;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> A >> B;
		cout << (A * A) / (B * B) << "\n";
	}

	return 0;
}