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

int main() {
	FASTIO;
	string S, T;
	vector<queue<int>> q(26, queue<int>());
	cin >> S >> T;
	FOR(i, 0, LEN(S) - 1) {
		q[S[i] - 'a'].push(i);
	}
	int idx = 0;
	int pos = -1;
	int ans = 0;
	while (true) {
		int ch = T[idx] - 'a';
		while (!q[ch].empty() && pos > q[ch].front()) {
			q[ch].pop();
		}
		if (!q[ch].empty()) {
			pos = q[ch].front();
			q[ch].pop();
		}
		else {
			break;
		}
		idx += 1;
		if (idx == LEN(T)) {
			pos = -1;
			ans++;
			idx = 0;
		}
	}
	cout << ans;

	return 0;
}