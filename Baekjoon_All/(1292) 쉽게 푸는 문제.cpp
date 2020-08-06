#include <iostream>
using namespace std;

int main() {
	int arr[1001];
	int A, B;
	int cnt = 0;
	int num = 1;
	int i = 1;
	int sum = 0;
	while (i <= 1000) {
		arr[i] = num;
		cnt++;
		if (cnt == num) {
			cnt = 0;
			num++;
		}
		i++;
	}
	cin >> A >> B;
	for (int i = A; i <= B; i++) {
		sum += arr[i];
	}
	cout << sum;

	return 0;
}