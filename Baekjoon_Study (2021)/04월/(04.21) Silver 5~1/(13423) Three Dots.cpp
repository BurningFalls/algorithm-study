#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll X[1001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N)
			cin >> X[i];
		sort(X + 1, X + N + 1);
		int cnt = 0;
		FOR(i, 1, N) {
			FOR(j, i + 1, N) {
				ll tmp = X[j] + (X[j] - X[i]);
				if (tmp > X[N]) continue;
				int lb = lower_bound(X + 1, X + N + 1, tmp) - X;
				if (X[lb] == tmp)
					cnt++;
			}
		}
		cout << cnt << "\n";
	}


	return 0;
}