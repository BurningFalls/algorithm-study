#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int gp[21][21];
int ori_gp[21][21];

int main() {
	int N;
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> gp[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				ori_gp[i][j] = 0;
			else
				ori_gp[i][j] = -1;
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j || i == k || j == k) continue;
				if (gp[i][j] == gp[i][k] + gp[k][j]) {
					ori_gp[i][j] = 0;
				}
				else if (gp[i][j] > gp[i][k] + gp[k][j]) {
					cout << -1;
					exit(0);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ori_gp[i][j] != 0) {
				ori_gp[i][j] = gp[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			sum += ori_gp[i][j];
		}
	}
	cout << sum;

	return 0;
}