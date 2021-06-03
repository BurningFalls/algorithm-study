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
	int ans = 0;
	FOR(i, 1, N + 1) {
		ans = A / B;
		int y = A % B;
		A = y * 10;
	}
	cout << ans;

	return 0;
}