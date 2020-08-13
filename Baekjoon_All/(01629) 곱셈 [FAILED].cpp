#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	long long int result = 1;
	cin >> A >> B >> C;
	for (int i = 0; i < B; i++) {
		result = (result * (A % C)) % C;
	}
	cout << result;

	return 0;
}