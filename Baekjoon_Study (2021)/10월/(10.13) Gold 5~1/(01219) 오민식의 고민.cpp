#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF -1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int N, S, E, M;
vector<pair<pii, ll>> edge;
vector<ll> city(100);
vector<ll> dist(100, LINF);
vector<bool> visited(100, 0);

void BF() {
	dist[S] = city[S];
	FOR(n, 1, N - 1) {
		FOR(i, 0, M - 1) {
			int a = edge[i].first.first;
			int b = edge[i].first.second;
			ll c = edge[i].second;
			if (dist[a] == LINF) continue;
			if (dist[b] < dist[a] - c + city[b]) {
				dist[b] = dist[a] - c + city[b];
			}
		}
	}
}

bool Check(int node) {
	if (node == E) {
		return true;
	}
	visited[node] = 1;
	bool flag = false;
	FOR(i, 0, M - 1) {
		int a = edge[i].first.first;
		int b = edge[i].first.second;
		ll c = edge[i].second;
		if (node != a) continue;
		if (visited[b]) continue;
		flag |= Check(b);
	}
	return flag;
}

int main() {
	FASTIO;
	cin >> N >> S >> E >> M;
	FOR(m, 0, M - 1) {
		int s, e;
		ll c;
		cin >> s >> e >> c;
		edge.push_back({ { s, e }, c });
	}
	FOR(i, 0, N - 1) {
		cin >> city[i];
	}
	BF();
	if (dist[E] == LINF) {
		cout << "gg";
		return 0;
	}
	bool flag = false;
	FOR(i, 0, M - 1) {
		int a = edge[i].first.first;
		int b = edge[i].first.second;
		ll c = edge[i].second;
		if (dist[a] == LINF) continue;
		if (dist[b] < dist[a] - c + city[b]) {
			fill(ALL(visited), 0);
			if (Check(a)) {
				flag = true;
				break;
			}
		}
	}
	if (flag)
		cout << "Gee";
	else
		cout << dist[E];


	return 0;
}