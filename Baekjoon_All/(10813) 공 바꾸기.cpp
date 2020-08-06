#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int a, b;
	int arr[101];
	int temp;
	for (int i = 1; i <= 100; i++) {
		arr[i] = i;
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}