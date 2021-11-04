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

int Parent[1001];
PQ<pair<int, pii>> pq;

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

bool is_Same(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	return n1 == n2;
}

void Union(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	Parent[min(n1, n2)] = max(n1, n2);
}

int MST(int N) {
	int cnt = 0;
	int ans = 0;
	while (!pq.empty() && cnt < N - 1) {
		int dist = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		if (!is_Same(a, b)) {
			Union(a, b);
			cnt++;
			ans += dist;
		}
	}
	if (cnt != N - 1) {
		return -1;
	}
	else {
		return ans;
	}
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		Parent[i] = i;
	}
	vector<char> S(N + 1);
	S[0] = ' ';
	FOR(i, 1, N) {
		cin >> S[i];
	}
	FOR(m, 1, M) {
		int u, v, d;
		cin >> u >> v >> d;
		if (S[u] != S[v]) {
			pq.push({ -d, {u, v} });
		}
	}
	cout << MST(N);


	return 0;
}