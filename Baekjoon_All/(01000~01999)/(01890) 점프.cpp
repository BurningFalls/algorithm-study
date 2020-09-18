#include <iostream>
#include <queue>
using namespace std;

int map[100][100];
long long accum[100][100];

long long jump(int n) {
	accum[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (accum[i][j] == 0 || map[i][j] == 0)
				continue;
			if (j + map[i][j] < n)
				accum[i][j + map[i][j]] += accum[i][j];
			if (i + map[i][j] < n)
				accum[i + map[i][j]][j] += accum[i][j];
		}
	}
	return accum[n - 1][n - 1];
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	cout << jump(N) << endl;
	return 0;
}