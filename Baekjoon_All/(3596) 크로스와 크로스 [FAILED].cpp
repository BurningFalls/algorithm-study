#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	cout << 2 - (((N - 1) / 5 + 1) % 2);

	return 0;
}