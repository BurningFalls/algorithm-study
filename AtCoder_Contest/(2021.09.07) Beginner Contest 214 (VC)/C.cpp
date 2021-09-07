#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pll pair<ll, int>
#define LEN(s) int(s.size())

ll S[200001];
ll T[200001];
ll ans[200001];

priority_queue<pll> pq;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> S[i];
	FOR(i, 1, N) {
		cin >> T[i];
		pq.push({ -T[i], i });
	}
	MEMSET(ans, -1);
	while (!pq.empty()) {
		ll t = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (ans[node] == -1) {
			ans[node] = t;
			pq.push({ -(t + S[node]), node % N + 1 });
		}
	}
	FOR(i, 1, N)
		cout << ans[i] << "\n";

	return 0;
}