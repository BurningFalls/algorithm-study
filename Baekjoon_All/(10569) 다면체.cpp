#include <iostream>
using namespace std;

int main() {
	int T;
	int V, E;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> V >> E;
		cout << E + 2 - V << endl;
	}

	return 0;
}