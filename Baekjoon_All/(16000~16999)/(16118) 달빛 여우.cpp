#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 4001

struct NUM {
	ll num;
	int flag;

	bool operator<(const NUM x) const {
		if (num == x.num)
			return flag < x.flag;
		return num < x.num;
	}
	NUM operator+(const NUM x) const{
		int tmp = flag + x.flag;
		return { num + x.num + tmp / 2, tmp % 2 };
	}
};

struct NODE {
	NUM dist;
	int node;
	int idx;

	bool operator<(const NODE x) const {
		return x.dist < dist;
	}
};

int N, M;
vector<vector<pll>> Edge(MAX, vector<pll>());
vector<NUM> dist1(MAX, { LINF, 0 });
vector<vector<NUM>> dist2(MAX, vector<NUM>(2, { LINF, 0 }));

void DT1() {
	PQ<NODE> pq;
	dist1[1] = { 0, 0 };
	pq.push({ {0, 0}, 1, 0 });
	while (!pq.empty()) {
		NUM dist = pq.top().dist;
		int cur = pq.top().node;
		pq.pop();
		if (dist1[cur] < dist) continue;
		FOR(i, 0, LEN(Edge[cur]) - 1) {
			int next = Edge[cur][i].first;
			NUM ndist = { Edge[cur][i].second, 0 };
			if (dist + ndist < dist1[next]) {
				dist1[next] = dist + ndist;
				pq.push({ dist1[next], next, 0 });
			}
		}
	}
}

void DT2() {
	PQ<NODE> pq;
	dist2[1][0] = {0, 0};
	pq.push({ {0, 0}, 1, 0 });
	while (!pq.empty()) {
		NUM dist = pq.top().dist;
		int cur = pq.top().node;
		int idx = pq.top().idx;
		pq.pop();
		if (dist2[cur][idx] < dist) continue;
		FOR(i, 0, LEN(Edge[cur]) - 1) {
			int next = Edge[cur][i].first;
			NUM ndist = { Edge[cur][i].second, 0 };
			int nidx = (idx + 1) % 2;
			if (idx == 0) {
				ndist = { ndist.num / 2, (int)(ndist.num % 2) };
			}
			else if (idx == 1) {
				ndist = { ndist.num * 2, 0 };
			}
			if (dist + ndist < dist2[next][nidx]) {
				dist2[next][nidx] = dist + ndist;
				pq.push({ dist2[next][nidx], next, nidx});
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b; ll d;
		cin >> a >> b >> d;
		Edge[a].push_back({ b, d });
		Edge[b].push_back({ a, d });
	}

	DT1();
	DT2();

	int ans = 0;
	FOR(i, 1, N) {
		NUM fox = dist1[i];
		NUM wolf = (dist2[i][0] < dist2[i][1] ? dist2[i][0] : dist2[i][1]);
		ans += (fox < wolf);
	}
	cout << ans;

	return 0;
}