#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
vector<int> v[100001];
pii ans[100001];


int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		int max_x = 0;
		FOR(i, 1, N) {
			int x, y;
			cin >> x >> y;
			ans[i] = { x, y };
			max_x = max(max_x, x);
		}
		FOR(i, 0, max_x)
			v[i].clear();
		FOR(i, 1, N) {
			v[ans[i].first].push_back(ans[i].second);
		}
		FOR(i, 0, max_x) {
			if (v[i].empty()) continue;
			sort(v[i].begin(), v[i].end());
		}
		int pos = 0;
		int idx = 1;
		FOR(i, 0, max_x) {
			if (v[i].empty()) continue;
			int len = v[i].size();
			if (v[i][0] == pos) {
				FOR(j, 0, len - 1) {
					ans[idx] = { i, v[i][j] };
					idx++;
				}
				pos = v[i][len - 1];
			}
			else if (v[i][len - 1] == pos) {
				ROF(j, len  - 1, 0) {
					ans[idx] = { i, v[i][j] };
					idx++;
				}
				pos = v[i][0];
			}
		}
		cin >> M;
		FOR(i, 1, M) {
			int query;
			cin >> query;
			cout << ans[query].first << " " << ans[query].second << "\n";
		}
	}


	return 0;
}