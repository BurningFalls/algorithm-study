#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

struct NODE {
	int u;
	int v;
	int w;
};

bool cmp(NODE a, NODE b) {
	return a.w < b.w;
}

vector<NODE> Edge;
int Parent[100001];
ll Cnt[100001];

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

ll Union(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	Parent[n1] = n2;
	ll tmp = Cnt[n1] * Cnt[n2];
	Cnt[n2] = Cnt[n2] + Cnt[n1];
	return tmp;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		Parent[i] = i;
		Cnt[i] = 1;
	}
	FOR(i, 1, N - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		Edge.push_back({ min(u, v), max(u, v), w });
	}
	sort(Edge.begin(), Edge.end(), cmp);
	ll ans = 0;
	for (NODE n : Edge)
		ans += n.w * Union(n.u, n.v);
	cout << ans;

	return 0;
}