#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

struct NODE {
	int left;
	int right;
	int idx;
};

bool compare(NODE a, NODE b) {
	if (a.left == b.left)
		return a.right > b.right;
	return a.left < b.left;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string t;
		int N;
		cin >> t;
		cin >> N;
		vector<NODE> range;
		FOR(i, 0, N - 1) {
			string s;
			cin >> s;
			if (LEN(t) < LEN(s)) continue;
			FOR(j, 0, LEN(t) - LEN(s)) {
				bool flag = true;
				FOR(k, 0, LEN(s) - 1) {
					if (t[j + k] != s[k]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					range.push_back({ j + 1, j + LEN(s), i + 1 });
				}
			}
		}

		sort(ALL(range), compare);

		if (range.empty()) {
			cout << "-1\n";
			continue;
		}

		vector<NODE> ans;
		int left = range[0].left, right = range[0].right;
		ans.push_back(range[0]);
		int idx = 1;
		while (idx < LEN(range)) {
			int maxi = -1;
			NODE tmp;
			while (idx < LEN(range) && range[idx].left <= right + 1) {
				if (maxi < range[idx].right) {
					maxi = range[idx].right;
					tmp = range[idx];
				}
				idx++;
			}
			if (maxi == -1) break;
			if (right < maxi) {
				right = maxi;
				ans.push_back(tmp);
			}
		}

		if (left != 1 || right != LEN(t)) {
			cout << -1 << "\n";
		}
		else {
			cout << LEN(ans) << "\n";
			FOR(i, 0, LEN(ans) - 1) {
				cout << ans[i].idx << " " << ans[i].left << "\n";
			}
		}
	}

	return 0;
}