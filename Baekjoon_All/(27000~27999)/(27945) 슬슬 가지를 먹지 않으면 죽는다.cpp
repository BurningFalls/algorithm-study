#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

struct NODE {
	int u;
	int v;
	int t;

	bool operator<(const NODE n) {
		return t < n.t;
	}
};

int N, M;
vector<NODE> edge;
vector<int> Parent(100001);

int Find(int node) {
	if (Parent[node] == node) {
		return node;
	}
	return Parent[node] = Find(Parent[node]);
}

bool is_Same(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
	return (n1 == n2);
}

void Union(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
	Parent[min(n1, n2)] = max(n1, n2);
}

int main() {
	FASTIO;
	cin >> N >> M;
	edge = vector<NODE>(M);
	FOR(i, 1, N) {
		Parent[i] = i;
	}
	FOR(i, 0, M - 1) {
		int u, v, t;
		cin >> u >> v >> t;
		edge[i] = { u, v, t };
	}
	sort(ALL(edge));

	int cnt = 0;
	vector<int> day;
	FOR(i, 0, M - 1) {
		bool flag = is_Same(edge[i].u, edge[i].v);
		if (!flag) {
			day.push_back(edge[i].t);
			Union(edge[i].u, edge[i].v);
		}
	}
	int pos = 1;
	FOR(i, 0, LEN(day) - 1) {
		if (pos == day[i]) {
			pos++;
		}
		else {
			break;
		}
	}
	cout << pos;

	return 0;
}