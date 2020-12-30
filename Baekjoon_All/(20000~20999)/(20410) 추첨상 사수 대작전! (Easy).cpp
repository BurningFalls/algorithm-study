#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int M, Seed, X1, X2;

pii func() {
	FOR(a, 0, M - 1) {
		FOR(c, 0, M - 1) {
			if (X1 == (a * Seed + c) % M) {
				if (X2 == (a * X1 + c) % M) {
					return { a, c };
				}
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> M >> Seed >> X1 >> X2;
	pii ans = func();
	cout << ans.first << " " << ans.second;

	return 0;
}