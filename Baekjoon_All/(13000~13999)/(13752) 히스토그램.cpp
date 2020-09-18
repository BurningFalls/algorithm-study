#include <iostream>
using namespace std;

int main() {
	int N;
	int K;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cout << "=";
		}
		cout << "\n";
	}

	return 0;
}