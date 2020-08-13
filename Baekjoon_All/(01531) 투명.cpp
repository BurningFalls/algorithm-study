#include <iostream>
using namespace std;

int main() {
	int N, M;
	int map[101][101] = { 0, };
	int x1, y1, x2, y2;
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j <= y2; j++) {
			for (int k = x1; k <= x2; k++) {
				map[j][k]++;
			}
		}
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] > M)
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}