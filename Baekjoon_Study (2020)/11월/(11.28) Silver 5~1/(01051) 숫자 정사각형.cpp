#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
char arr[52][52];
int maximum = 1;

void Func(int k) {
	FOR(i, 1, N - k + 1) {
		FOR(j, 1, M - k + 1) {
			char a = arr[i][j];
			char b = arr[i][j + k - 1];
			char c = arr[i + k - 1][j];
			char d = arr[i + k - 1][j + k - 1];
			if (a == b && b == c && c == d) {
				maximum = max(maximum, k);
				return;
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
		}
	}
	FOR(k, 2, min(N, M)) {
		Func(k);
	}
	cout << maximum * maximum;

	return 0;
}