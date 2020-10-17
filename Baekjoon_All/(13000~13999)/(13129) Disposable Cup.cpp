#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int A, B, N;
	cin >> A >> B >> N;
	int ans = A * N + B;
	FOR(i, 0, N - 1) {
		cout << ans << " ";
		ans += B;
	}

	return 0;
}