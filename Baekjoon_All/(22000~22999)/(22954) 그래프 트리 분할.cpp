#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int Parent[100001];
vector<int> edge[100001];
bool used[200001];

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
	cin >> N >> M;
	FOR(i, 1, N)
		Parent[i] = i;
	FOR(i, 1, M)
		used[i] = 1;
	FOR(i, 1, M) {
		int u, v;
		cin >> u >> v;
		if (is_Same(u, v))
			used[i] = 0;
		else {
			Union(min(u, v), max(u, v));
			edge[u].push_back(i);
			edge[v].push_back(i);
		}
	}
	set<int> se;
	FOR(i, 1, N) {
		se.insert(Find_Parent(i));
	}
	int se_len = se.size();
	if (se_len == 1) {
		if (N <= 2)
			cout << -1;
		else {
			int vertex_idx = 0;
			int edge_idx = 0;
			FOR(i, 1, N) {
				int len = edge[i].size();
				if (len == 1) {
					vertex_idx = i;
					edge_idx = edge[i][0];
					break;
				}
			}
			cout << 1 << " " << N - 1 << "\n";
			cout << vertex_idx << "\n";
			FOR(i, 1, N) {
				if (i == vertex_idx) continue;
				cout << i << " ";
			}
			cout << "\n";
			FOR(i, 1, M) {
				if (used[i] == 0) continue;
				if (i == edge_idx) continue;
				cout << i << " ";
			}
		}
	}
	else if (se_len == 2) {
		int A = *(se.begin());
		int B = *(--se.end());
		vector<int> A_vt, B_vt;
		set<int> A_eg, B_eg;
		FOR(i, 1, N) {
			if (Find_Parent(i) == A)
				A_vt.push_back(i);
			else if (Find_Parent(i) == B)
				B_vt.push_back(i);
		}
		sort(A_vt.begin(), A_vt.end());
		sort(B_vt.begin(), B_vt.end());
		FOR(i, 0, A_vt.size() - 1) {
			int edge_len = edge[A_vt[i]].size();
			FOR(j, 0, edge_len - 1) {
				A_eg.insert(edge[A_vt[i]][j]);
			}
		}
		FOR(i, 0, B_vt.size() - 1) {
			int edge_len = edge[B_vt[i]].size();
			FOR(j, 0, edge_len - 1) {
				B_eg.insert(edge[B_vt[i]][j]);
			}
		}
		if (A_vt.size() == B_vt.size())
			cout << -1;
		else {
			cout << A_vt.size() << " " << B_vt.size() << "\n";
			for (int x : A_vt)
				cout << x << " ";
			cout << "\n";
			if (A_eg.size() != 0) {
				for (auto it = A_eg.begin(); it != A_eg.end(); it++)
					cout << (*it) << " ";
				cout << "\n";
			}
			for (int x : B_vt)
				cout << x << " ";
			if (B_eg.size() != 0) {
				cout << "\n";
				for (auto it = B_eg.begin(); it != B_eg.end(); it++)
					cout << (*it) << " ";
			}
		}
	}
	else {
		cout << -1;
	}


	return 0;
}