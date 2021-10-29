#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pii> v(N);
		vector<pii> ans;
		FOR(i, 0, N - 1) {
			int num;
			cin >> num;
			v[i] = { num, i + 1 };
		}
		sort(ALL(v));
		int idx = 0;
		int prev = v[0].first;
		while (idx <= N - 1 && v[idx].first == prev) {
			idx++;
		}
		if (idx == N) {
			cout << "NO\n";
			continue;
		}
		FOR(i, 0, idx - 2) {
			ans.push_back({ v[i].second, v[idx].second });
		}
		while (idx <= N - 1) {
			int start = idx - 1;
			prev = v[idx].first;
			while (idx <= N - 1 && v[idx].first == prev) {
				idx++;
			}
			FOR(i, start + 1, idx - 1) {
				ans.push_back({ v[start].second, v[i].second });
			}
		}
		cout << "YES\n";
		for (pii x : ans) {
			cout << x.first << " " << x.second << "\n";
		}
	}

	return 0;
}