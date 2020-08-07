#include <iostream>
using namespace std;

int main() {
	int T;
	int num;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> num;
		cout << "Pairs for " << num << ": ";
		if (num % 2 == 0) {
			for (int i = 1; i < num / 2; i++) {
				cout << i << " " << num - i;
				if (i != num / 2 - 1)
					cout << ", ";
			}
			cout << "\n";
		}
		else if (num % 2 == 1) {
			for (int i = 1; i <= num / 2; i++) {
				cout << i << " " << num - i;
				if (i != num / 2)
					cout << ", ";
			}
			cout << "\n";
		}
	}

	return 0;
}