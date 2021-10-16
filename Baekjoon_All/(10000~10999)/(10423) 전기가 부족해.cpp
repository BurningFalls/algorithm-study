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
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

PQ<pair<int, pii>> pq;
vector<int> Parent(1001);
vector<bool> Connected(1001, 0);

pii Find_Parent(int node) {
	if (Parent[node] == node)
		return { node, Connected[node] };
	pii tmp = Find_Parent(Parent[node]);
	Parent[node] = tmp.first;
	Connected[node] = tmp.second;
	return tmp;
}

bool Union(int n1, int n2) {
	pii tmp1 = Find_Parent(n1);
	pii tmp2 = Find_Parent(n2);
	if (tmp1.first == tmp2.first)
		return 0;
	if (tmp1.second && tmp2.second)
		return 0;
	if (tmp1.second) {
		Parent[tmp2.first] = tmp1.first;
	}
	else {
		Parent[tmp1.first] = tmp2.first;
	}
	return 1;
}

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	FOR(i, 1, N) {
		Parent[i] = i;
	}
	FOR(i, 1, K) {
		int k;
		cin >> k;
		Connected[k] = 1;
	}
	FOR(i, 1, M) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push({ -w, {u, v} });
	}
	int ans = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;
		pq.pop();
		if (Union(n1, n2)) {
			ans += cost;
		}
	}
	cout << ans;

	return 0;
}