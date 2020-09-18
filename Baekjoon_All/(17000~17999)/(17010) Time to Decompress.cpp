#include <iostream>
using namespace std;

int main() {
	int T;
	int num;
	char X;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> num >> X;
		for (int j = 0; j < num; j++) {
			cout << X;
		}
		cout << "\n";
	}

	return 0;
}