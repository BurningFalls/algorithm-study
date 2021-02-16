#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>

int N;
int S[11], B[11];
bool choose[11] = { 0, };
int ans = -1;

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1) {
		cin >> S[i] >> B[i];
	}
	FOR(num, 1, pow(2, N) - 1) {
		int X = 1, Y = 0;
		FOR(j, 0, 9) {
			if (num & (1 << j)) {
				X *= S[j];
				Y += B[j];
			}
		}
		if (ans == -1)
			ans = abs(X - Y);
		else
			ans = min(ans, abs(X - Y));
	}
	cout << ans;

	return 0;
}