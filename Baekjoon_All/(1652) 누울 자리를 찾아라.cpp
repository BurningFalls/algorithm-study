#include <iostream>
using namespace std;

char arr[101][101];

int main() {
	int N;
	int sum1 = 0, sum2 = 0;
	int cnt;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '.') {
				cnt++;
				if (cnt == 2) {
					sum1++;
				}
			}
			else
				cnt = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) {
			if (arr[j][i] == '.') {
				cnt++;
				if (cnt == 2) {
					sum2++;
				}
			}
			else
				cnt = 0;
		}
	}
	cout << sum1 << " " << sum2;

	return 0;
}