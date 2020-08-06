#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int a, b;
	string arr[6] = { "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh" };
	string arr_same[6] = { "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh" };
	cin >> T;
	for (int A = 0; A < T; A++) {
		cin >> a >> b;
		cout << "Case " << A + 1 << ": ";
		if (a == b) {
			cout << arr_same[a - 1] << "\n";
		}
		else if ((a == 5 && b == 6) || (a == 6 && b == 5)) {
			cout << "Sheesh Beesh" << "\n";
		}
		else {
			cout << arr[max(a, b) - 1] << " " << arr[min(a, b) - 1] << "\n";
		}
	}

	return 0;
}