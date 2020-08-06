#include <iostream>
using namespace std;

int main() {
	int T;
	int candy;
	int brother;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> candy >> brother;
		cout << "You get " << candy / brother << " piece(s) and your dad gets " << candy % brother << " piece(s).\n";
	}


	return 0;
}