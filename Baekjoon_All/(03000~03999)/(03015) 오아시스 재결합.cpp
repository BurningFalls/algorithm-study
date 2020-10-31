#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	vector<pii> v;
	ll ans = 0;
	int num;
	cin >> N;
	FOR(i, 1, N) {
		cin >> num;
		if (v.empty()) {
			v.push_back({ num, 1 });
			continue;
		}
		while (!v.empty() && v.back().first < num) {
			ans += v.back().second;
			v.pop_back();
		}
		if (v.empty()) {
			v.push_back({ num, 1 });
			continue;
		}
		if (v.back().first > num) {
			v.push_back({ num, 1 });
			ans++;
		}
		else if (v.back().first == num) {
			ans += v.back().second;
			if (v.size() > 1)
				ans++;
			v.back().second++;
		}
	}
	cout << ans;

	return 0;
}