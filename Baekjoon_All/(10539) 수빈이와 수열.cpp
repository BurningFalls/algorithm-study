#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N];
	int* ans = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	ans[0] = arr[0];
	for (int i = 1; i < N; i++) {
		ans[i] = arr[i] * (i + 1) - arr[i - 1] * i;
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}


	return 0;
}