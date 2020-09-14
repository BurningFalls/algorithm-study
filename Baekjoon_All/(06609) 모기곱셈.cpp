#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int M, P, L, E, R, S, N;
	while (cin >> M >> P >> L >> E >> R >> S >> N) {
		FOR(i, 1, N) {
			int a, b, c;
			a = P / S;
			b = L / R;
			c = M * E;
			M = a;
			P = b;
			L = c;
		}
		cout << M << "\n";
	}

	return 0;
}