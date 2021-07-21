#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int Ufind[27][200003] = { 0, };
char block_idx[200003];

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	FOR(i, 1, K) {
		string s;
		cin >> s;
		int uidx = -1;
		FOR(j, 0, M) {
			Ufind[i][j] = uidx;
			if (j == M) continue;
			if (s[j] == 'U') {
				uidx = j;
			}
		}
	}

	FOR(i, 1, N)
		cin >> block_idx[i];
	int idx = block_idx[N] - 'A' + 1;
	int right = M - 1;
	int left = Ufind[idx][right] + 1;
	ll ans = 0;
	ans += (ll)right - left + 1;
	ROF(i, N - 1, 1) {
		idx = block_idx[i] - 'A' + 1;
		right = Ufind[idx][right + 1];
		left = Ufind[idx][left] + 1;
		ans += (ll)right - left + 1;
	}
	cout << ans;

	return 0;
}