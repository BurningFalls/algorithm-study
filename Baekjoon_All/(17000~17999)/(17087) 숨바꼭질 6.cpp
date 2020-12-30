#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int N, S;
	cin >> N >> S;
	int ans = 0;
	FOR(i, 1, N) {
		int A;
		cin >> A;
		if (i == 1)
			ans = abs(S - A);
		else
			ans = GCD(ans, abs(S - A));
	}
	cout << ans;

	return 0;
}