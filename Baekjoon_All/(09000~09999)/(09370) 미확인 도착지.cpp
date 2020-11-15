#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 98765432

vector<pii> v[2001];
int dist[2001];
vector<int> ans_v;

void DT(int start) {
	priority_queue<pii> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)
			continue;
		int len = v[cur].size();
		FOR(i, 0, len - 1) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M, t;
		int s, g, h;
		int gtoh = 0;
		cin >> N >> M >> t;
		cin >> s >> g >> h;
		ans_v.clear();
		FOR(i, 1, N) {
			dist[i] = INF;
			v[i].clear();
		}
		FOR(i, 1, M) {
			int a, b, d;
			cin >> a >> b >> d;
			d *= 2;
			if ((a == g && b == h) || (a == h && b == g))
				d -= 1;
			v[a].push_back({ b, d });
			v[b].push_back({ a, d });
		}
		DT(s);
		FOR(i, 1, t) {
			int x;
			cin >> x;
			if (dist[x] % 2 != 0)
				ans_v.push_back(x);
		}
		sort(ans_v.begin(), ans_v.end());
		int len = ans_v.size();
		FOR(i, 0, len - 1)
			cout << ans_v[i] << " ";
		cout << "\n";
	}

	return 0;
}