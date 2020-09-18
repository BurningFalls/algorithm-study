#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string K;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		temp = K[K.size() - 1] - '0';
		if (temp % 2 == 0)
			cout << "even\n";
		else
			cout << "odd\n";
	}

	return 0;
}