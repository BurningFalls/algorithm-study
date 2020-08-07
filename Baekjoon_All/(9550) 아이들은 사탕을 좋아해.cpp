#include <iostream>
using namespace std;

int main() {
	int T;
	int N, K;
	int arr[101];
	int sum;
	cin >> T;
	for (int a = 0; a < T; a++) {
		sum = 0;
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= N; i++) {
			sum += arr[i] / K;
		}
		cout << sum << endl;
	}


	return 0;
}