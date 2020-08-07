#include <iostream>
using namespace std;

int main() {
	long long int N;
	cin >> N;
	cout << ((3 * N * N + 5 * N + 2) / 2) % 45678 << endl;

	return 0;
}