#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	long long int temp;
	cin >> A >> B >> C;
	temp = A;
	for (int i = 0; i < C; i++) {
		temp ^= B;
	}
	cout << temp;

	return 0;
}