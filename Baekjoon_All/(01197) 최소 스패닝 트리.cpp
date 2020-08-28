#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int V, E;
vector<tuple<int, int, ll>> v;
int parent[10001];

bool compare(tuple<int, int, ll> a, tuple<int, int, ll> b) {
	return get<2>(a) < get<2>(b);
}

int Find_Parent(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = Find_Parent(parent[node]);
}

bool Same_Parent(int node1, int node2) {
	node1 = Find_Parent(node1);
	node2 = Find_Parent(node2);
	return node1 == node2;
}

void Union(int node1, int node2) {
	node1 = Find_Parent(node1);
	node2 = Find_Parent(node2);
	if (node1 < node2)
		parent[node2] = node1;
	else if (node1 >= node2)
		parent[node1] = node2;
}

int main() {
	FASTIO;
	ll ans = 0;
	cin >> V >> E;
	FOR(i, 1, E) {
		int A, B;
		ll C;
		cin >> A >> B >> C;
		v.push_back({ A, B, C });
	}
	FOR(i, 1, V)
		parent[i] = i;
	sort(v.begin(), v.end(), compare);
	FOR(i, 0, E - 1) {
		int n1 = get<0>(v[i]);
		int n2 = get<1>(v[i]);
		ll w = get<2>(v[i]);
		if (!Same_Parent(n1, n2)) {
			Union(n1, n2);
			ans += w;
		}
	}
	cout << ans;

	return 0;
}