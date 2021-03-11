#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, L;
vector<pii> v;

int main() {
	FASTIO;
	cin >> N >> L;
	FOR(i, 1, N) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s, e });
	}
	sort(v.begin(), v.end());
	int idx = 0;
	int ans = 0;
	int end_pos = 0;
	while (idx < N) {
		int start = v[idx].first;
		int end = v[idx].second;
		if (end <= end_pos) {
			idx++;
			continue;
		}
		if (start <= end_pos) {
			start = end_pos + 1;
		}
		int tmp = (end - start) / L;
		if ((end - start) % L != 0)
			tmp += 1;
		ans += tmp;
		end_pos = start + L * tmp - 1;
		idx++;
	}
	cout << ans;


	return 0;
}