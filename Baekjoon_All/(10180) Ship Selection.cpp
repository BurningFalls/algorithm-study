#include <iostream>
using namespace std;

int main() {
	int T;
	int N, D;
	double v, f, c;
	int cnt;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N >> D;
		cnt = 0;
		for (int i = 0; i < N; i++) {
			cin >> v >> f >> c;
			if ((D / v) * c <= f)
				cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}