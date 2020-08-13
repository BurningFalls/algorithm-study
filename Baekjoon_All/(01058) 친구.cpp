#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[51][51];
	char a;
	int N;
	int fnd[51][51];
	int cnt = 0;
	int maximum = -1;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			if (a == 'Y')
				arr[i][j] = 1;
			else if (a == 'N')
				arr[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (arr[i][j] == 1) {
				cnt++;
				continue;
			}
			for (int k = 0; k < N; k++) {
				if (k == i || k == j) continue;
				if (arr[i][k] == 1 && arr[k][j] == 1) {
					cnt++;
					break;
				}
			}
		}
		maximum = max(maximum, cnt);
	}

	cout << maximum;

	return 0;
}