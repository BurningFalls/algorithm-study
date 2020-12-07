#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
ld arr[501];
ld Sum[501];
ld minimum = -1;

int main() {
	FASTIO;
	cin >> N >> K;
	Sum[0] = 0;
	FOR(i, 1, N) {
		cin >> arr[i];
		Sum[i] = Sum[i - 1] + arr[i];
	}
	FOR(i, 1, N - K + 1) {
		FOR(j, i + K - 1, N) {
			ld m = Sum[j] - Sum[i - 1];
			ld ans = 0;
			ld cnt = j - i + 1;
			m /= cnt;
			FOR(k, i, j)
				ans += (arr[k] - m) * (arr[k] - m);
			ans /= cnt;
			if (minimum == -1)
				minimum = sqrt(ans);
			else
				minimum = min(minimum, sqrt(ans));
		}
	}
	cout << fixed << setprecision(6);
	cout << minimum;

	return 0;
}