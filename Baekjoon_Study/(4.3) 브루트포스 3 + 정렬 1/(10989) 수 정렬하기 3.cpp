#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	int num;
	int arr[10001] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[num]++;
	}
	for (int i = 1; i <= 10000; i++) {
		while (arr[i]) {
			cout << i << "\n";
			arr[i]--;
		}
	}

	return 0;
}