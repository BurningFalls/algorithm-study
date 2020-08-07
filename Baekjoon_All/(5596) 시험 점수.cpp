#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num;
	int S = 0, T = 0;
	for (int i = 0; i < 4; i++) {
		cin >> num;
		S += num;
	}
	for (int i = 0; i < 4; i++) {
		cin >> num;
		T += num;
	}
	cout << max(S, T);

	return 0;
}