#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

vector<int> v;
int cnt[1000001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	int prev, cur;
	FOR(i, 1, N) {
		cin >> cur;
		if (i == 1) {
			v.push_back(cur);
			prev = cur;
		}
		else {
			if (prev > cur) {
				v.push_back(cur);
				prev = cur;
			}
		}
	}
	int idx = 1;
	FOR(i, 0, v[0] - 1)
		cnt[i] = 1;
	ROF(i, v[0] - 1, v[v.size() - 1]) {
		cnt[i % v[idx]] += cnt[i];
		if (i == v[idx]) {
			idx++;
		}
	}
	double ans = 0;
	FOR(i, 0, v[v.size() - 1] - 1) {
		ans += i * cnt[i];
	}
	cout << fixed << setprecision(9);
	cout << ans / v[0];

	return 0;
}