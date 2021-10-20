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

int Find_Parent(int node, vector<int>& Parent, vector<int>& Dist) {
	if (Parent[node] == node) {
		return node;
	}
	int tmp = Find_Parent(Parent[node], Parent, Dist);
	Dist[node] += Dist[Parent[node]];
	return Parent[node] = tmp;
}

void Union(int n1, int n2, vector<int>& Parent, vector<int>& Dist) {
	Dist[n1] = abs(n1 - n2) % 1000;
	Parent[n1] = n2;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vvi Edge(N + 1, vi());
		vector<int> Parent(N + 1);
		vector<int> Dist(N + 1, 0);
		FOR(i, 1, N) {
			Parent[i] = i;
		}
		while (true) {
			char order;
			int a, b;
			cin >> order;
			if (order == 'O') break;
			if (order == 'E') {
				cin >> a;
				Find_Parent(a, Parent, Dist);
				cout << Dist[a] << "\n";
			}
			else if (order == 'I') {
				cin >> a >> b;
				Union(a, b, Parent, Dist);
			}
		}
	}


	return 0;
}