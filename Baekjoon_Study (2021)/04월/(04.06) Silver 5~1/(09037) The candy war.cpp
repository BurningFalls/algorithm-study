#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int C[11];

bool Check() {
	FOR(i, 1, N - 1) {
		if (C[i] != C[i + 1])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		FOR(i, 1, N)
			cin >> C[i];
		int ans = 0;
		int ch_C[11];
		FOR(i, 1, N) {
			if (C[i] % 2 == 1)
				C[i] += 1;
		}
		while (!Check()) {
			FOR(i, 1, N) {
				ch_C[i] = -C[i] / 2;
				ch_C[i] += C[(i + N - 2) % N + 1] / 2;
			}
			FOR(i, 1, N) {
				C[i] += ch_C[i];
			}
			FOR(i, 1, N) {
				if (C[i] % 2 == 1)
					C[i] += 1;
			}
			ans++;
		}
		cout << ans << "\n";
	}


	return 0;
}