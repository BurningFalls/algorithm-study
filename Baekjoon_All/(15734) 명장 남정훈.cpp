#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int L, R, A;
	cin >> L >> R >> A;
	while (A > 0) {
		if (L >= R) {
			R += 1;
			A--;
		}
		else if (L < R) {
			L += 1;
			A--;
		}
	}
	cout << min(L, R) * 2;

	return 0;
}