#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
priority_queue<pair<int, pair<int, int>>> pq;
int Parent[1001];
int ans = 0;

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

int is_Same(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	return n1 == n2;
}

void Union(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	Parent[n2] = n1;
}

void MST() {
	int cnt = 0;
	while(cnt < N - 1) {
		int cost = -pq.top().first;
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;
		pq.pop();
		if (!is_Same(n1, n2)) {
			Union(n1, n2);
			ans += cost;
			cnt++;
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N)
		Parent[i] = i;
	FOR(i, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b) continue;
		pq.push({ -c, {a, b} });
	}
	MST();
	cout << ans;

	return 0;
}