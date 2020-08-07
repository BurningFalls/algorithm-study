#include <iostream>
using namespace std;

int N, B;
int arr1[6][6];
int arr2[6][6];
int ans[6][6] = { 0, };

int main() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr1[i][j];
			arr2[i][j] = arr1[i][j];
		}
	}
	for (int T = 0; T < B - 1; T++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					ans[i][j] = (ans[i][j] + arr1[i][k] * arr2[k][j]) % 1000;
				}
			}
		}
		if (T != B - 2) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					arr1[i][j] = ans[i][j];
					ans[i][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}