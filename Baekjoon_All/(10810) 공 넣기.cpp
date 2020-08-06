#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M;
	int a, b, c;
	int arr[101] = { 0, };
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		for (int j = a; j <= b; j++) {
			arr[j] = c;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}