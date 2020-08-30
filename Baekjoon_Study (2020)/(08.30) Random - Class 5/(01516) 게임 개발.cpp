#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 987654321
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N;
vector<int> v[501];
int T[501];
int cnt[501] = { 0, };
int ans[501] = { 0, };

void TP() {
	queue<pair<int, int>> q;
	FOR(i, 1, N) {
		if (cnt[i] == 0) {
			q.push({ i, T[i] });
			ans[i] = T[i];
		}
	}
	while(!q.empty()) {
		int n = q.front().first;
		int t = q.front().second;
		q.pop();
		int len = v[n].size();
		FOR(i, 0, len - 1) {
			int nn = v[n][i];
			int nt = t + T[nn];
			cnt[nn]--;
			ans[nn] = max(ans[nn], nt);
			if (cnt[nn] == 0) {
				q.push({ nn, ans[nn] });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> T[i];
		int num;
		while (true) {
			cin >> num;
			if (num == -1)
				break;
			v[num].push_back(i);
			cnt[i]++;
		}
	}
	TP();
	FOR(i, 1, N)
		cout << ans[i] << "\n";

	return 0;
}