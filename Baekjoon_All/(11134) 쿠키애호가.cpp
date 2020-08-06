#include <iostream>
using namespace std;

int main() {
	int T;
	int N, C;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N >> C;
		if (N % C == 0)
			cout << N / C << "\n";
		else
			cout << N / C + 1 << "\n";
	}

	return 0;
}