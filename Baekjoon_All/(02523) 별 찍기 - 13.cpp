#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = N - i; j >= 1; j--) {
			cout << "*";
		}
		cout << endl;
	}
}