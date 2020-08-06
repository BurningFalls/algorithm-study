#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int N, r, c;
	int answer = 0;
	cin >> N >> r >> c;
	int B;

	while (N >= 1) {
		B = pow(2, N - 1);
		if (r < B && c < B) {
			;
		}
		else if (r < B && c >= B) {
			answer += 1 * B * B;
			c -= B;
		}
		else if (r >= B && c < B) {
			answer += 2 * B * B;
			r -= B;
		}
		else if (r >= B && c >= B) {
			answer += 3 * B * B;
			c -= B;
			r -= B;
		}
		N--;
	}
	cout << answer;

	return 0;
}