#include <iostream>
#include <math.h>
using namespace std;

bool arr[4000101] = { 0, };

bool Check(int n) {
	if (n == 2)
		return true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	int sum = 0;
	int cnt = 0;
	int start = 2, end = 2;
	int k = 0;
	cin >> N;
	for (int i = 2; i <= N + 100; i++) {
		if (Check(i))
			arr[i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		if (arr[i]) {
			sum += i;
			if (sum >= N) {
				end = i;
				break;
			}
		}
	}
	if (arr[N])
		cnt++;
	while (start <= N / 2 && end <= N) {
		if (sum <= N) {
			if (sum == N)
				cnt++;
			k = end + 1;
			while (true) {
				if (arr[k]) {
					sum += k;
					end = k;
					break;
				}
				k++;
			}
		}
		else if (sum > N) {
			sum -= start;
			k = start + 1;
			while (true) {
				if (arr[k]) {
					start = k;
					break;
				}
				k++;
			}
		}
	}
	cout << cnt;

	return 0;
}