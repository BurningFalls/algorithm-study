#include <iostream>
using namespace std;

int main() {
	int T;
	int n;
	int loc;
	cin >> T;
	for (int a = 0; a < T; a++) {
		loc = 0;
		cin >> n;
		while (n != 1) {
			if (n % 2 == 1) {
				cout << loc << " ";
			}
			n /= 2;
			loc++;
		}
		cout << loc << endl;
	}
	return 0;
}