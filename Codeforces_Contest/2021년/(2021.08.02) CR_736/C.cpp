#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int cnt[200001] = { 0, };

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		if (a < b)
			cnt[a]++;
		else if (b < a)
			cnt[b]++;
	}
	int Q;
	int ans = 0;
	FOR(i, 1, N) {
		if (cnt[i] == 0)
			ans++;
	}
	cin >> Q;
	FOR(q, 1, Q) {
		int kind, u, v;
		cin >> kind;
		if (kind == 1) {
			cin >> u >> v;
			if (u < v) {
				if (cnt[u] == 0)
					ans--;
				cnt[u]++;
			}
			else if (v < u) {
				if (cnt[v] == 0)
					ans--;
				cnt[v]++;
			}
		}
		else if (kind == 2) {
			cin >> u >> v;
			if (u < v) {
				cnt[u]--;
				if (cnt[u] == 0)
					ans++;
			}
			else if (v < u) {
				cnt[v]--;
				if (cnt[v] == 0)
					ans++;
			}
		}
		else if (kind == 3) {
			cout << ans << "\n";
		}
	}



	return 0;
}