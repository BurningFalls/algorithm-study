#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
char arr[1026][1026];

void Func(int n, int sy, int sx) {
	if (n == 1) {
		arr[sy][sx] = '*';
		return;
	}
	Func(n / 2, sy, sx);
	Func(n / 2, sy, sx + n / 2);
	Func(n / 2, sy + n / 2, sx);
}

int main() {
	FASTIO;
	FOR(i, 0, 1025) {
		FOR(j, 0, 1025) {
			arr[i][j] = ' ';
		}
	}
	cin >> N;
	N = pow(2, N);

	Func(N, 0, 0);

	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1 - i) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

	return 0;
}