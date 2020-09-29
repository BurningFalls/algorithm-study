#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int n, m;
int Parent[1000001];

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

int main() {
	FASTIO;
	cin >> n >> m;
	FOR(i, 1, n)
		Parent[i] = i;
	FOR(i, 1, m) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			Union(b, c);
		}
		else if (a == 1) {
			if (is_Same(b, c))
				cout << "YES";
			else
				cout << "NO";
			cout << "\n";
		}
	}

	return 0;
}