#include <iostream>
#include <string>
using namespace std;

int rela[1001][1001] = { 0, };

int main() {
	int N, M;
	int a, b;
	int cnt;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		rela[a][b] = 1;
		rela[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (rela[i][j] == 1) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}