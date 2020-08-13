#include <iostream>
using namespace std;

int main() {
	int T;
	int m, n;
	bool map[101][101];
	int node;
	int sum;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		sum = 0;
		for (int i = 0; i < n; i++) {
			node = 0;
			for (int j = m - 1; j >= 0; j--) {
				if (map[j][i] == 1) {
					sum += (m - 1) - j - node;
					node++;
				}
			}
		}
		cout << sum << "\n";
	}

	return 0;
}