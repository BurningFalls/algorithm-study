#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	int n;
	int sum;
	cin >> T;

	for (int a = 0; a < T; a++) {
		sum = 0;
		while (scanf("%d", &n)) {
			sum += n;
			if (getchar() == '\n')
				break;
		}
		cout << sum << "\n";
	}

	return 0;
}