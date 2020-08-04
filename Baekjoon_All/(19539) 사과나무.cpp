#include <iostream>
using namespace std;

int arr[100001];

int main() {
	int N;
	int sum = 0;
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] % 2 == 1)
			cnt++;
		sum += arr[i];
	}
	if (sum % 3 != 0)
		cout << "NO";
	else {
		if (sum / 3 < cnt)
			cout << "NO";
		else
			cout << "YES";
	}

	return 0;
}