#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	char arr[11][11];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}