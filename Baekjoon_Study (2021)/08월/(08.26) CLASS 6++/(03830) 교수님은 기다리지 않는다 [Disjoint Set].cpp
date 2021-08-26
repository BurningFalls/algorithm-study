#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 100001

int N, M;
int Parent[MAX];
int Diff[MAX];

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	int root = Find_Parent(Parent[node]);
	Diff[node] += Diff[Parent[node]];
	return Parent[node] = root;
}

bool is_Same(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	return n1 == n2;
}

void Union(int n1, int n2, int w) {
	int n1_root = Find_Parent(n1);
	int n2_root = Find_Parent(n2);
	Parent[n1_root] = n2_root;
	Diff[n1_root] = Diff[n2] - (Diff[n1] - w);
}

int main() {
	FASTIO;
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		FOR(i, 1, N) {
			Parent[i] = i;
			Diff[i] = 0;
		}
		FOR(i, 1, M) {
			char kind;
			int a, b, w;
			cin >> kind;
			if (kind == '!') {
				cin >> a >> b >> w;
				if (is_Same(a, b)) continue;
				Union(a, b, w);
			}
			else if (kind == '?') {
				cin >> a >> b;
				if (!is_Same(a, b))
					cout << "UNKNOWN";
				else
					cout << Diff[a] - Diff[b];
				cout << "\n";
			}
		}
	}


	return 0;
}