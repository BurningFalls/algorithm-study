#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 100001

int N, M1, M2;
int Parent1[MAX], Parent2[MAX];
vector<pii> v;

int Find_Parent(int node, int idx) {
	if (idx == 1) {
		if (Parent1[node] == node)
			return node;
		return Parent1[node] = Find_Parent(Parent1[node], 1);
	}
	else if (idx == 2) {
		if (Parent2[node] == node)
			return node;
		return Parent2[node] = Find_Parent(Parent2[node], 2);
	}
}

bool is_Same(int n1, int n2, int idx) {
	n1 = Find_Parent(n1, idx);
	n2 = Find_Parent(n2, idx);
	return n1 == n2;
}

void Union(int n1, int n2, int idx) {
	n1 = Find_Parent(n1, idx);
	n2 = Find_Parent(n2, idx);
	if (idx == 1)
		Parent1[n2] = n1;
	else if (idx == 2)
		Parent2[n2] = n1;
}

int main() {
	FASTIO;
	int road1 = 0, road2 = 0;
	cin >> N >> M1 >> M2;
	FOR(i, 1, N) {
		Parent1[i] = i;
		Parent2[i] = i;
	}
	FOR(i, 1, M1) {
		int u, v;
		cin >> u >> v;
		Union(min(u, v), max(u, v), 1);
		road1++;
	}
	FOR(i, 1, M2) {
		int u, v;
		cin >> u >> v;
		Union(min(u, v), max(u, v), 2);
		road2++;
	}
	bool flag = false;
	if (!(road1 == N - 1 || road2 == N - 1)) {
		FOR(i, 1, N) {
			int pi1 = Find_Parent(i, 1);
			int pi2 = Find_Parent(i, 2);
			FOR(j, i + 1, N) {
				int pj1 = Find_Parent(j, 1);
				int pj2 = Find_Parent(j, 2);
				if (pi1 != pj1 && pi2 != pj2) {
					Union(i, j, 1);
					Union(i, j, 2);
					v.push_back({ i, j });
					road1++;
					road2++;
					if (road1 == N - 1 || road2 == N - 1) {
						flag = true;
						break;
					}
				}
			}
			if (flag)
				break;
		}
	}
	int len = v.size();
	cout << len << "\n";
	for (pii x : v)
		cout << x.first << " " << x.second << "\n";


	return 0;
}