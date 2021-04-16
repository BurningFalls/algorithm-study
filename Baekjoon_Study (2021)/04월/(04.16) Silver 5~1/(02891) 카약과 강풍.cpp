#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int cnt[11];
int tmp[11];

int main() {
	FASTIO;
	int N, S, R;
	cin >> N >> S >> R;
	FOR(i, 1, N)
		cnt[i] = 1;
	FOR(i, 1, S) {
		int x;
		cin >> x;
		cnt[x] -= 1;
	}
	FOR(i, 1, R) {
		int x;
		cin >> x;
		cnt[x] += 1;
	}
	FOR(i, 1, N) {
		tmp[i] = cnt[i];
	}
	int ans = 0;
	FOR(i, 1, N) {
		if (tmp[i] == 2) {
			if (i != 1 && tmp[i - 1] == 0) {
				tmp[i - 1] += 1;
				tmp[i] -= 1;
			}
			else if (i != N && tmp[i + 1] == 0) {
				tmp[i + 1] += 1;
				tmp[i] -= 1;
			}
		}
	}
	FOR(i, 1, N) {
		if (tmp[i] == 0)
			ans++;
	}
	cout << ans;



	return 0;
}