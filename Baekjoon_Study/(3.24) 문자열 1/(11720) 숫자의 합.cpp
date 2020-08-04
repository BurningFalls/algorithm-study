#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	char* arr = new char[N];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] - '0';
		sum += arr[i];
	}
	cout << sum << endl;


	return 0;
}