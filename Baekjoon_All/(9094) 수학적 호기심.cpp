#include <iostream>
using namespace std;

int main() {
	int T;
	int N, M;
	int cnt;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cnt = 0;
		cin >> N >> M;
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if ((i * i + j * j + M) % (i * j) == 0)
					cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}