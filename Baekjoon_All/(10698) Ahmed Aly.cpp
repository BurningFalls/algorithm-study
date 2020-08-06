#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	int X, Y, Z;
	char C, D;
	int cs = 1;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> X >> C >> Y >> D >> Z;
		cout << "Case " << cs << ": ";
		if (C == '+') {
			if (X + Y == Z)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if (C == '-') {
			if (X - Y == Z)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		cs++;
	}

	return 0;
}