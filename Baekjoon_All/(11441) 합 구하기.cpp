#include <iostream>
using namespace std;

int arr[100001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	int M;
	int num;
	int a, b;
	cin >> N;
	arr[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << "\n";
	}

	return 0;
}