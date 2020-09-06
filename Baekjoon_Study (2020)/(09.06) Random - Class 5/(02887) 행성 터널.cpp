#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 2000000001
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N;
vector<tuple<int, int, int, int>> v;
priority_queue<pair<int, pair<int, int>>> pq;
int Parent[100001];
ll ans = 0;

bool compare1(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	return get<0>(a) < get<0>(b);
}

bool compare2(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	return get<1>(a) < get<1>(b);
}

bool compare3(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	return get<2>(a) < get<2>(b);
}

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

bool Same_Parent(int node1, int node2) {
	int Parent1 = Find_Parent(node1);
	int Parent2 = Find_Parent(node2);
	return Parent1 == Parent2;
}

void Union(int node1, int node2) {
	int Parent1 = Find_Parent(node1);
	int Parent2 = Find_Parent(node2);
	Parent[Parent1] = Parent2;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({ x, y, z, i });
	}
	sort(v.begin(), v.end(), compare1);
	FOR(i, 0, N - 2) {
		int cost = abs(get<0>(v[i]) - get<0>(v[i + 1]));
		pq.push({ -cost, {get<3>(v[i]), get<3>(v[i + 1])} });
	}
	sort(v.begin(), v.end(), compare2);
	FOR(i, 0, N - 2) {
		int cost = abs(get<1>(v[i]) - get<1>(v[i + 1]));
		pq.push({ -cost, {get<3>(v[i]), get<3>(v[i + 1])} });
	}
	sort(v.begin(), v.end(), compare3);
	FOR(i, 0, N - 2) {
		int cost = abs(get<2>(v[i]) - get<2>(v[i + 1]));
		pq.push({ -cost, {get<3>(v[i]), get<3>(v[i + 1])} });
	}

	FOR(i, 1, N)
		Parent[i] = i;

	while(!pq.empty()) {
		int cost = -pq.top().first;
		int node1 = pq.top().second.first;
		int node2 = pq.top().second.second;
		pq.pop();
		if (!Same_Parent(node1, node2)) {
			Union(node1, node2);
			ans += cost;
		}
	}

	cout << ans;

	return 0;
}