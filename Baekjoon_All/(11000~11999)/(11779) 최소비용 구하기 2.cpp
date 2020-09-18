#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 987654321
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M;
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>> pq;
int dist[1001] = { 0, };
int path[1001] = { 0, };

void DT(int s) {
	FOR(i, 1, N)
		dist[i] = INF;
	pq.push({ 0, s });
	dist[s] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		int n = pq.top().second;
		pq.pop();
		if (dist[n] < d)
			continue;
		int len = v[n].size();
		FOR(i, 0, len - 1) {
			int nn = v[n][i].first;
			int nd = v[n][i].second + dist[n];
			if (dist[nn] > nd) {
				path[nn] = n;
				dist[nn] = nd;
				pq.push({ -nd, nn });
			}
		}
	}
}

int main() {
	FASTIO;
	int start, end;
	vector<int> ans;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	cin >> start >> end;
	DT(start);
	int n = end;
	while (n) {
		ans.push_back(n);
		n = path[n];
	}
	int len = ans.size();
	cout << dist[end] << "\n";
	cout << len << "\n";
	ROF(i, len - 1, 0)
		cout << ans[i] << " ";

	return 0;
}