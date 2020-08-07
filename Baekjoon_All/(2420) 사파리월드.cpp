#include <iostream>
using namespace std;

int main() {
	long long int N, M;
	long long int ans;
	cin >> N >> M;
	if (N >= M)
		ans = N - M;
	else if (N < M)
		ans = M - N;
	cout << ans;

	return 0;
}