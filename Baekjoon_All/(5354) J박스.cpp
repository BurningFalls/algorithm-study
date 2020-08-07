#include <iostream>
using namespace std;

int main() {
	int T;
	char map[11][11];
	int N;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			map[0][i] = '#';
			map[N - 1][i] = '#';
			map[i][0] = '#';
			map[i][N - 1] = '#';
		}
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < N - 1; j++) {
				map[i][j] = 'J';
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}