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

bool Check(map<int, int>& mp, int a, int b, vector<int>& tmp) {
	vector<pii> v;
	for (auto t : mp) {
		v.push_back(t);
	}
	bool flag1 = true, flag2 = true, flag3 = true;
	FOR(i, 0, LEN(v) - 2) {
		if (v[i].first + 1 != v[i + 1].first) {
			flag1 = false;
		}
	}
	FOR(i, 0, LEN(v) - 1) {
		if (v[i].second != tmp[i]) {
			flag2 = false;
		}
	}
	FOR(i, 0, LEN(v) - 1) {
		if (v[i].second != tmp[LEN(v) - 1 - i]) {
			flag3 = false;
		}
	}
	return flag1 && (flag2 || flag3);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int R, C;
		cin >> R >> C;
		map<int, int> y, x;
		int cnt = 0;
		FOR(i, 0, R - 1) {
			FOR(j, 0, C - 1) {
				char c;
				cin >> c;
				if (c == '#') {
					cnt++;
					y[i]++;
					x[j]++;
				}
			}
		}
		bool ans = false;
		FOR(i, 2, min(R, C)) {
			FOR(j, 1, i - 1) {
				if (cnt != i * i - j * j) continue;
				if (LEN(y) != i || LEN(x) != i) continue;
				vector<int> tmp;
				FOR(k, 1, i - j) {
					tmp.push_back(i);
				}
				FOR(k, 1, j) {
					tmp.push_back(i - j);
				}

				bool f1 = Check(y, i, j, tmp);
				bool f2 = Check(x, i, j, tmp);
				if (f1 && f2) {
					ans = true;
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}