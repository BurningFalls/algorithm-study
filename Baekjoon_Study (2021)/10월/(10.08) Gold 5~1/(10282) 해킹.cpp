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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int N, D, C;
vector<vector<pii>> edge(10001);
vector<int> infected(10001);

void Func() {
	PQ<pii> pq;
	infected[C] = 0;
	pq.push({ 0, C });
	while (!pq.empty()) {
		int timing = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (infected[node] < timing) continue;
		FOR(i, 0, LEN(edge[node]) - 1) {
			int next = edge[node][i].first;
			int ntime = timing + edge[node][i].second;
			if (infected[next] > ntime) {
				infected[next] = ntime;
				pq.push({ -ntime, next });
			}
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		fill(ALL(edge), vector<pii>());
		fill(ALL(infected), INF);
		cin >> N >> D >> C;
		FOR(i, 1, D) {
			int a, b, s;
			cin >> a >> b >> s;
			edge[b].push_back({ a, s });
		}
		Func();
		int cnt = 0;
		int maxi = 0;
		FOR(i, 1, N) {
			if (infected[i] == INF) continue;
			cnt++;
			maxi = max(maxi, infected[i]);
		}
		P2(cnt, maxi);
	}


	return 0;
}