#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M;
vector<pii> all_v;
vector<int> x_v, y_v;

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int y, x;
		cin >> y >> x;
		all_v.push_back({ y, x });
		x_v.push_back(x);
		y_v.push_back(y);
	}
	sort(x_v.begin(), x_v.end());
	sort(y_v.begin(), y_v.end());
	int my = y_v[M / 2];
	int mx = x_v[M / 2];
	int ans = 0;
	FOR(i, 0, M - 1) {
		ans += abs(my - all_v[i].first) + abs(mx - all_v[i].second);
	}
	cout << ans;


	return 0;
}