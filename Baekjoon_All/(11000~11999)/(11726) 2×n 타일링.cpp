#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[1001];
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i < n + 1; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	cout << arr[n] << endl;
	return 0;
}