#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> v[7];

int main() {
	FASTIO;
	int N, P;
	cin >> N >> P;
	int ans = 0;
	FOR(i, 1, N) {
		int x, y;
		cin >> x >> y;
		if (v[x].empty()) {
			v[x].push_back(y);
			ans++;
		}
		else {
			int cnt = 0;
			while (!v[x].empty() && v[x].back() > y) {
				v[x].pop_back();
				cnt++;
			}
			ans += cnt;
			if ((v[x].empty()) || (!v[x].empty() && v[x].back() != y)) {
				ans += 1;
				v[x].push_back(y);
			}
		}
	}
	cout << ans;

	return 0;
}