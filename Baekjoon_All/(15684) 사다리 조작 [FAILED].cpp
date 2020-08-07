#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H;
bool connect[32][12] = { 0, };
int result[11];

int Laddering(int row, int col) {
	for (int row = 1; row <= H; row++) {
		if (connect[row][col - 1])
			col--;
		else if (connect[row][col])
			col++;
	}
	return col;
}

void Change_Ladder(int cnt, int y) {
	int cor_cnt = 0;
	if (cnt > 3) {
		return;
	}

	for (int i = 1; i <= N; i++) {
		result[Laddering(1, i)] = i;
	}
	for (int i = 1; i <= N; i++) {
		if (result[i] == i)
			cor_cnt++;
		else
			break;
	}
	if (cor_cnt == N) {
		cout << cnt;
		exit(0);
	}

	for (int i = y; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {
			if (connect[i][j]) continue;
			if (connect[i][j - 1]) continue;
			if (connect[i][j + 1]) continue;
			connect[i][j] = 1;
			Change_Ladder(cnt + 1, i);
			connect[i][j] = 0;
		}
	}
}


int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int a, b;
	// connect[x][1] -> x번 가로선에서, 1번 세로선과 2번 세로선의 연결 상태
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		connect[a][b] = 1;
	}

	Change_Ladder(0, 1);

	cout << -1;

	return 0;
}