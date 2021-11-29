#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

bool is_Prime(int x) {
	if (x == 1) {
		return false;
	}
	int sqrtx = sqrt(x);
	FOR(i, 2, sqrtx) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, E;
		cin >> N >> E;
		vector<int> v(N);
		vector<int> visited(N, 0);
		vector<int> one_idx;
		FOR(i, 0, N - 1) {
			cin >> v[i];
			if (v[i] == 1) {
				one_idx.push_back(i);
			}
		}
		for(int i : one_idx) {
			if (visited[i]) continue;
			int left = i, right = i;
			int cnt = 1;
			while (left - E >= 0 && v[left - E] == 1) {
				left -= E;
				cnt++;
			}
			while (right + E < N && v[right + E] == 1) {
				right += E;
				cnt++;
			}
			for (int j = left; j <= right; j += E) {
				visited[j] = cnt;
			}
		}
		ll ans = 0;
		FOR(i, 0, N - 1) {
			if (!is_Prime(v[i])) continue;
			ll left = 0, right = 0;
			if (i - E >= 0) {
				left = visited[i - E];
			}
			if (i + E < N) {
				right = visited[i + E];
			}
			ans += (left + 1) * (right + 1) - 1;
		}
		cout << ans << "\n";
	}

	return 0;
}