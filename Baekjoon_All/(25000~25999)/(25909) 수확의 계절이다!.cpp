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

map<pii, vector<int>> mp;

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	int left = 1, right = 0;
	int y = 0, x = 0, tim = 0;
	FOR(i, 0, N - 1) {
		char a; int b;
		cin >> a >> b;
		right += b;
		FOR(j, 1, b) {
			tim++;
			if (a == 'N') y++;
			else if (a == 'E') x++;
			else if (a == 'S') y--;
			else if (a == 'W') x--;
			mp[{y, x}].push_back(tim);
		}
	}

	int ans = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			int prev = 0;
			FOR(cur, 1, LEN((*it).second) - 1) {
				if (((*it).second)[cur] - ((*it).second)[prev] >= mid) {
					cnt++;
					prev = cur;
				}
			}
		}
		if (cnt >= K) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else if (cnt < K) {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}