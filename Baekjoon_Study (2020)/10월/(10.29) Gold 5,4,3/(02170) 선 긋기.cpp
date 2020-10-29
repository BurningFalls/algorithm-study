#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<pii> v;

int main() {
	FASTIO;
	int N;
	int left, right;
	int ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		v.push_back({ min(a, b), max(a, b) });
	}
	sort(v.begin(), v.end());
	left = v[0].first;
	right = v[0].second;
	FOR(i, 1, N - 1) {
		if (right < v[i].first) {
			ans += right - left;
			left = v[i].first;
			right = v[i].second;
		}
		else if (v[i].first <= right) {
			right = max(v[i].second, right);
		}
	}
	ans += right - left;
	cout << ans;

	return 0;
}