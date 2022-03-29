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

int N, W, T, K;
vector<int> F(6);
int ans = 0;

void DFS(int Time, int pos, int not_dec) {
	vector<int> dec(N, 0);
	FOR(i, 0, N - 1) {
		if (i == not_dec) continue;
		int cnt = 0;
		if (i == 0) {
			cnt += (F[i + 1] > 0);
		}
		else if (i == N - 1) {
			cnt += (F[i - 1] > 0);
		}
		else {
			cnt += (F[i + 1] > 0) + (F[i - 1] > 0);
		}
		if (cnt == 0) {
			dec[i] = 3;
		}
		else if (cnt == 1) {
			dec[i] = 2;
		}
		else if (cnt == 2) {
			dec[i] = 1;
		}
	}
	FOR(i, 0, N - 1) {
		F[i] -= dec[i];
	}
	if (Time == T) {
		int surv = 0;
		FOR(i, 0, N - 1) {
			surv += (F[i] > 0);
		}
		if (surv >= K) {
			ans++;
		}
		FOR(i, 0, N - 1) {
			F[i] += dec[i];
		}
		return;
	}
	FOR(new_pos, max(0, pos - 1), min(N - 1, pos + 1)) {
		DFS(Time + 1, new_pos, new_pos);
	}
	FOR(i, 0, N - 1) {
		F[i] += dec[i];
	}
}

int main() {
	FASTIO;
	cin >> N >> W >> T >> K;
	FOR(i, 0, N - 1) {
		cin >> F[i];
	}
	DFS(1, W, -1);
	cout << ans;

	return 0;
}