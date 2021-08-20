#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 500001

int N;
int Parent[MAX];

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
	Parent[n2] = n1;
}

int main() {
	FASTIO;
	int M;
	cin >> N >> M;
	FOR(i, 1, N)
		Parent[i] = i;
	int ans = 0;
	FOR(i, 1, M) {
		int u, v;
		cin >> u >> v;
		if (is_Same(min(u, v), max(u, v))) {
			if (ans == 0)
				ans = i;
		}
		else
			Union(min(u, v), max(u, v));
	}
	cout << ans;

	return 0;
}