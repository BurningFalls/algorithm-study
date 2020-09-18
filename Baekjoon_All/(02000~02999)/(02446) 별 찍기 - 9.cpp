#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i - 1; j++) {
			cout << " ";
		}
		for (int j = 1; j <= (2 * N + 1) - 2 * i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= (N - 1) - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= 2 * i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
}