#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[21][21] = { 0, };
int show[21][21] = { 0, };

bool Check(int num) {
	int x = 1;
	FOR(col, 1, 19) {
		int cnt = 0;
		FOR(row, 1, 20) {
			if (arr[col][row] == num) {
				cnt++;
			}
			else {
				if (cnt == 5)
					return true;
				cnt = 0;
			}
		}
	}

	FOR(row, 1, 19) {
		int cnt = 0;
		FOR(col, 1, 20) {
			if (arr[col][row] == num) {
				cnt++;
			}
			else {
				if (cnt == 5)
					return true;
				cnt = 0;
			}
		}
	}

	FOR(diag, 6, 20) {
		int cnt = 0;
		ROF(col, diag - 1, 0) {
			int row = diag - col;
			if (arr[col][row] == num) {
				cnt++;
			}
			else {
				if (cnt == 5)
					return true;
				cnt = 0;
			}
		}
	}

	FOR(diag, 21, 34) {
		int cnt = 0;
		ROF(col, 19, diag - 20) {
			int row = diag - col;
			if (arr[col][row] == num) {
				cnt++;
			}
			else {
				if (cnt == 5)
					return true;
				cnt = 0;
			}
		}
	}

	ROF(diag, 14, 0) {
		int cnt = 0;
		FOR(col, diag + 1, 20) {
			int row = col - diag;
			if (arr[col][row] == num) {
				cnt++;
			}
			else {
				if (cnt == 5)
					return true;
				cnt = 0;
			}
		}
	}

	FOR(diag, 1, 14) {
		int cnt = 0;
		FOR(col, 1, 20 - diag) {
			int row = col + diag;
			if (arr[col][row] == num) {
				cnt++;
			}
			else {
				if (cnt == 5)
					return true;
				cnt = 0;
			}
		}
	}

	return false;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	int ans = 9999;
	FOR(i, 1, N) {
		int y, x;
		cin >> y >> x;
		if (i % 2 == 1)
			arr[y][x] = 1;
		else if (i % 2 == 0)
			arr[y][x] = 2;
		if (Check(1) || Check(2))
			ans = min(ans, i);
	}
	cout << ((ans == 9999) ? -1 : ans);

	return 0;
}