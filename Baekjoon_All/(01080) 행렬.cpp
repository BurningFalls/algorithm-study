#include <iostream>
using namespace std;

char A[51][51];
char B[51][51];
int N, M;

void Change(int y, int x) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (A[y + i][x + j] == '0')
				A[y + i][x + j] = '1';
			else if (A[y + i][x + j] == '1')
				A[y + i][x + j] = '0';
		}
	}
}

bool Compare() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j])
				return false;
		}
	}
	return true;
}

int main() {
	int ans = 0;
	int match_flag = false;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B[i][j];
		}
	}

	if (N < 3 || M < 3) {
		if (Compare())
			cout << 0;
		else
			cout << -1;
	}
	else {
		for (int i = 0; i <= N - 3; i++) {
			for (int j = 0; j <= M - 3; j++) {
				if (A[i][j] != B[i][j]) {
					Change(i, j);
					ans++;
					if (Compare()) {
						match_flag = true;
						j = M - 3;
						i = N - 3;
					}
				}
			}
		}
		if (match_flag) {
			cout << ans;
		}
		else {
			cout << -1;
		}
	}

	return 0;
}