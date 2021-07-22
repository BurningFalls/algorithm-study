#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007

int N;
bool possible[502][502];
int cycle_idx[502];
vector<int> cycle[502];
int cycle_around_len[502] = { 0, };

ll cal1(ll a) {
	ll result = 1;
	FOR(i, 1, a) {
		result = (result * i) % MOD;
	}
	return result;
}

ll cal2(ll a, ll b) {
	ll result = 1;
	FOR(i, 1, b) {
		result = (result * a) % MOD;
	}
	return result;
}

int main() {
	FASTIO;
	memset(cycle_idx, -1, sizeof(cycle_idx));
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> possible[i][j];
		}
	}
	int cycle_cnt = 0;
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			if (!(possible[i][j] && possible[j][i])) continue;
			if (cycle_idx[i] == -1 && cycle_idx[j] == -1) {
				cycle_idx[i] = cycle_cnt;
				cycle_idx[j] = cycle_cnt;
				cycle[cycle_cnt].push_back(i);
				cycle[cycle_cnt].push_back(j);
				cycle_cnt++;
			}
			else if (cycle_idx[j] == -1) {
				cycle_idx[j] = cycle_idx[i];
				cycle[cycle_idx[i]].push_back(j);
			}
		}
	}
	FOR(i, 0, cycle_cnt - 1) {
		int len = cycle[i].size();
		int node = cycle[i][0];
		FOR(j, 1, N) {
			if (cycle_idx[j] == -1 && possible[j][node]) {
				int cnt = 0;
				FOR(k, 1, N) {
					if (j == k) continue;
					if (possible[j][k])
						cnt++;
				}
				if (cnt == len)
					cycle_around_len[i]++;
			}
		}
	}
	ll ans = 1;
	FOR(i, 0, cycle_cnt - 1) {
		ll cycle_len = cycle[i].size();
		ll tmp1 = cal1(cycle_len - 1);
		ll tmp2 = cal2(cycle_len, cycle_around_len[i]);
		ans = (ans * tmp1) % MOD;
		ans = (ans * tmp2) % MOD;
	}
	cout << ans;


	return 0;
}