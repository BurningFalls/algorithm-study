#include <iostream>
using namespace std;

int main() {
	int E, S, M;
	int num = 0;
	int e, s, m;
	cin >> E >> S >> M;
	while (true) {
		e = num % 15 + 1;
		s = num % 28 + 1;
		m = num % 19 + 1;
		if (E == e && S == s && M == m) {
			cout << num + 1 << endl;
			break;
		}
		num++;
	}

	return 0;
}