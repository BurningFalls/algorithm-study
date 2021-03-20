#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
char Map[101][101];
ll sum[101][101] = { 0, };
ll maximum = 0;

ll Calc(int sy, int sx, int ey, int ex) {
	return sum[ey][ex] - sum[ey][sx - 1] - sum[sy - 1][ex] + sum[sy - 1][sx - 1];
}

void Func() {
	ll sum1, sum2, sum3;
	FOR(a, 1, N - 2) {
		FOR(b, a + 1, N - 1) {
			sum1 = Calc(1, 1, a, M);
			sum2 = Calc(a + 1, 1, b, M);
			sum3 = Calc(b + 1, 1, N, M);
			maximum = max(maximum, sum1 * sum2 * sum3);
		}
	}
	FOR(a, 1, M - 2) {
		FOR(b, a + 1, M - 1) {
			sum1 = Calc(1, 1, N, a);
			sum2 = Calc(1, a + 1, N, b);
			sum3 = Calc(1, b + 1, N, M);
			maximum = max(maximum, sum1 * sum2 * sum3);
		}
	}
	FOR(a, 1, N - 1) {
		FOR(b, 1, M - 1) {
			sum1 = Calc(1, 1, a, b);
			sum2 = Calc(a + 1, 1, N, b);
			sum3 = Calc(1, b + 1, N, M);
			maximum = max(maximum, sum1 * sum2 * sum3);
		}
	}
	FOR(a, 1, N - 1) {
		FOR(b, 1, M - 1) {
			sum1 = Calc(1, 1, N, b);
			sum2 = Calc(1, b + 1, a, M);
			sum3 = Calc(a + 1, b + 1, N, M);
			maximum = max(maximum, sum1 * sum2 * sum3);
		}
	}
	FOR(a, 1, N - 1) {
		FOR(b, 1, M - 1) {
			sum1 = Calc(1, 1, a, b);
			sum2 = Calc(1, b + 1, a, M);
			sum3 = Calc(a + 1, 1, N, M);
			maximum = max(maximum, sum1 * sum2 * sum3);
		}
	}
	FOR(a, 1, N - 1) {
		FOR(b, 1, M - 1) {
			sum1 = Calc(1, 1, a, M);
			sum2 = Calc(a + 1, 1, N, b);
			sum3 = Calc(a + 1, b + 1, N, M);
			maximum = max(maximum, sum1 * sum2 * sum3);
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (Map[i][j] - '0');
		}
	}
	Func();
	cout << maximum;

	return 0;
}