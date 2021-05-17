#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	long double arr[11];
	arr[0] = 1;
	FOR(i, 1, 10)
		arr[i] = arr[i - 1] * i;
	int N, M, K;
	cin >> N >> M >> K;
	long double up, down;
	double ans = 0;
	while (K <= M) {
		if (N + K - 2 * M < 0) {
			K++;
			continue;
		}
		up = arr[M] * arr[M] * arr[N - M] * arr[N - M];
		down = arr[N] * arr[K] * arr[M - K] * arr[M - K] * arr[N + K - 2 * M];
		double temp = up / down;
		ans += temp;
		K++;
	}
	cout << fixed << setprecision(9);
	cout << ans;


	return 0;
}