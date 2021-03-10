#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M, R;
int A[101][101];
pii dest[7][101][101];
int ch_A[101][101];

void Set(int order) {
	if (order == 1) {
		FOR(i, 1, N) FOR(j, 1, M)
			dest[1][i][j] = { N + 1 - i, j };
	}
	else if (order == 2) {
		FOR(i, 1, N) FOR(j, 1, M)
			dest[2][i][j] = { i, M + 1 - j };
	}
	else if (order == 3) {
		FOR(i, 1, N) FOR(j, 1, M)
			dest[3][i][j] = { j, N + 1 - i };
	}
	else if (order == 4) {
		FOR(i, 1, N) FOR(j, 1, M)
			dest[4][i][j] = { M + 1 - j, i };
	}
	else if (order == 5) {
		FOR(i, 1, N / 2) FOR(j, 1, M / 2)
			dest[5][i][j] = { i, j + M / 2 };
		FOR(i, 1, N / 2) FOR(j, M / 2 + 1, M)
			dest[5][i][j] = { i + N / 2, j };
		FOR(i, N / 2 + 1, N) FOR(j, 1, M / 2)
			dest[5][i][j] = { i - N / 2, j };
		FOR(i, N / 2 + 1, N) FOR(j, M / 2 + 1, M)
			dest[5][i][j] = { i, j - M / 2 };
	}
	else if (order == 6) {
		FOR(i, 1, N / 2) FOR(j, 1, M / 2)
			dest[6][i][j] = { i + N / 2, j };
		FOR(i, 1, N / 2) FOR(j, M / 2 + 1, M)
			dest[6][i][j] = { i, j - M / 2 };
		FOR(i, N / 2 + 1, N) FOR(j, 1, M / 2)
			dest[6][i][j] = { i, j + M / 2 };
		FOR(i, N / 2 + 1, N) FOR(j, M / 2 + 1, M)
			dest[6][i][j] = { i - N / 2, j };
	}
}

void DoIt(int order) {
	Set(order);
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			int y = dest[order][i][j].first;
			int x = dest[order][i][j].second;
			ch_A[y][x] = A[i][j];
		}
	}
	if (order == 3 || order == 4)
		swap(N, M);
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			A[i][j] = ch_A[i][j];
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> R;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> A[i][j];
		}
	}
	FOR(i, 1, R) {
		int order;
		cin >> order;
		DoIt(order);
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}