#include <iostream>
#include <algorithm>
using namespace std;

int A[2000001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = N; i < N + M; i++) {
		cin >> A[i];
	}
	sort(A, A + (N + M));
	for (int i = 0; i < N + M; i++) {
		cout << A[i] << " ";
	}

	return 0;
}