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

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> cnt(100001, 0);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}

	ll ans = 0;
	int left = 0;
	FOR(i, 0, N - 1) {
		cnt[v[i]]++;
		if (cnt[v[i]] >= 2) {
			while (left < N && v[left] != v[i]) {
				cnt[v[left]]--;
				left++;
			}
			cnt[v[left]]--;
			left++;
		}
		ans += (i - left + 1);
	}
	cout << ans;

	return 0;
}