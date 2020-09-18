#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[101];
	int v;
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> v;
	for (int i = 0; i < N; i++) {
		if (arr[i] == v)
			cnt++;
	}
	cout << cnt;

	return 0;
}