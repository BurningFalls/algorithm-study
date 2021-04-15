#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[30][30];

int main() {
	FASTIO;
	int M, N;
	cin >> M >> N;
	int U, L, R, D;
	cin >> U >> L >> R >> D;
	FOR(i, 1, M + U + D) {
		FOR(j, 1, N + L + R) {
			if ((i + j) % 2 == 0)
				arr[i][j] = '#';
			else if ((i + j) % 2 == 1)
				arr[i][j] = '.';
		}
	}
	FOR(i, U + 1, U + M) {
		FOR(j, L + 1, L + N) {
			cin >> arr[i][j];
		}
	}

	FOR(i, 1, M + U + D) {
		FOR(j, 1, N + L + R) {
			cout << arr[i][j];
		}
		cout << "\n";
	}


	return 0;
}