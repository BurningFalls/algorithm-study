
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct compare {
	bool operator()(pii a, pii b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	}
};

priority_queue<pii, vector<pii>, compare> pq;

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		while (!pq.empty()) pq.pop();
		int N, K;
		string s;
		int ans = 0;
		cin >> N >> K;
		cin >> s;
		FOR(i, 0, N - 1) {
			if (s[i] == 'W') {
				if (i != 0 && s[i - 1] == 'W')
					ans += 2;
				else
					ans += 1;
			}
		}
		if (K == 0) {
			cout << ans << "\n";
			continue;
		}
		int cnt = 0;
		int idx = 0;
		while (s[idx] == 'L') {
			idx++;
		}
		if (idx != 0)
			pq.push({ idx, 1 });
		if (idx == N) {
			cout << 2 * K - 1 << "\n";
			continue;
		}
		FOR(i, idx, N - 1) {
			if (s[i] == 'W' && cnt != 0) {
				pq.push({ cnt, 0 });
				cnt = 0;
			}
			else if (s[i] == 'L') {
				cnt++;
			}
		}
		if (cnt != 0)
			pq.push({ cnt, 1 });
		while (K > 0) {
			if (pq.empty())
				break;
			int n = pq.top().first;
			int flag = pq.top().second;
			pq.pop();
			if (K >= n) {
				K -= n;
				if (flag == 0)
					ans += 2 * n + 1;
				else if (flag == 1)
					ans += 2 * n;
			}
			else if (K < n) {
				ans += 2 * K;
				break;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}