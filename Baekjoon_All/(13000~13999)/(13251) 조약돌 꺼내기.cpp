#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>

double arr[51];

int main() {
	FASTIO;
	int M, K;
	int N = 0;
	double ans = 0;
	cin >> M;
	FOR(i, 1, M) {
		cin >> arr[i];
		N += arr[i];
	}
	cin >> K;
	double temp;
	FOR(i, 1, M) {
		if (arr[i] < K) continue;
		temp = 1;
		FOR(j, 1, K) {
			temp *= (arr[i] - (j - 1)) / (N - (j - 1));
		}
		ans += temp;
	}
	cout << fixed << setprecision(10);
	cout << ans;

	return 0;
}