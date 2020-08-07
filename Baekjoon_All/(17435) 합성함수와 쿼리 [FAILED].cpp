#include <iostream>
using namespace std;

int arr[200001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int M, Q;
	int n, x;
	cin >> M;
	for (int i = 1; i <= M; i++)
		cin >> arr[i];
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> n >> x;
		for (int j = 0; j < n; j++)
			x = arr[x];
		cout << x << "\n";
	}


	return 0;
}