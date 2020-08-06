#include <iostream>
using namespace std;

int main() {
	int N, K;
	int S, Y;
	int arr[7][2] = { 0, };
	int sum = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> S >> Y;
		arr[Y][S] += 1;
	}
	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j < 2; j++) {
			if (arr[i][j] == 0) continue;
			if (arr[i][j] % K == 0)
				sum += arr[i][j] / K;
			else
				sum += (arr[i][j] / K + 1);
		}
	}
	cout << sum;

	return 0;
}