#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int s;
char arr[25][132];

void Set(int n, int num) {
	if (num == 1) {
		FOR(i, n + 1, n + s)
			arr[1][i] = '-';
	}
	else if (num == 2) {
		FOR(i, 2, s + 1)
			arr[i][n] = '|';
	}
	else if (num == 3) {
		FOR(i, 2, s + 1)
			arr[i][n + s + 1] = '|';
	}
	else if (num == 4) {
		FOR(i, n + 1, n + s)
			arr[s + 2][i] = '-';
	}
	else if (num == 5) {
		FOR(i, s + 3, 2 * s + 2)
			arr[i][n] = '|';
	}
	else if (num == 6) {
		FOR(i, s + 3, 2 * s + 2)
			arr[i][n + s + 1] = '|';
	}
	else if (num == 7) {
		FOR(i, n + 1, n + s)
			arr[2 * s + 3][i] = '-';
	}
}

void Make(int n, int num) {
	if (num == 1) {
		Set(n, 3);
		Set(n, 6);
	}
	else if (num == 2) {
		Set(n, 1);
		Set(n, 3);
		Set(n, 4);
		Set(n, 5);
		Set(n, 7);
	}
	else if (num == 3) {
		Set(n, 1);
		Set(n, 3);
		Set(n, 4);
		Set(n, 6);
		Set(n, 7);
	}
	else if (num == 4) {
		Set(n, 2);
		Set(n, 3);
		Set(n, 4);
		Set(n, 6);
	}
	else if (num == 5) {
		Set(n, 1);
		Set(n, 2);
		Set(n, 4);
		Set(n, 6);
		Set(n, 7);
	}
	else if (num == 6) {
		Set(n, 1);
		Set(n, 2);
		Set(n, 4);
		Set(n, 5);
		Set(n, 6);
		Set(n, 7);
	}
	else if (num == 7) {
		Set(n, 1);
		Set(n, 3);
		Set(n, 6);
	}
	else if (num == 8) {
		Set(n, 1);
		Set(n, 2);
		Set(n, 3);
		Set(n, 4);
		Set(n, 5);
		Set(n, 6);
		Set(n, 7);
	}
	else if (num == 9) {
		Set(n, 1);
		Set(n, 2);
		Set(n, 3);
		Set(n, 4);
		Set(n, 6);
		Set(n, 7);
	}
	else if (num == 0) {
		Set(n, 1);
		Set(n, 2);
		Set(n, 3);
		Set(n, 5);
		Set(n, 6);
		Set(n, 7);
	}
}

int main() {
	FASTIO;
	FOR(i, 0, 24)
		FOR(j, 0, 131)
			arr[i][j] = ' ';
	string n;
	cin >> s >> n;
	int len = n.size();
	FOR(i, 0, len - 1) {
		int tmp = n[i] - '0';
		Make(1 + (s + 3) * i, tmp);
	}
	FOR(i, 1, 2 * s + 3) {
		FOR(j, 1, (s + 3) * len) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

	return 0;
}