#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int Q[200001];
int use[200001];
int Parent[200001];

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

void Union(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	Parent[n1] = n2;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N)
			cin >> Q[i];
		MEMSET(use, 0);
		int prev = 0;
		FOR(i, 1, N) {
			if (prev != Q[i]) {
				use[Q[i]] = 1;
				prev = Q[i];
			}
		}
		Q[0] = 0;
		int idx = 1;
		while (use[idx] == 1)
			idx++;
		FOR(i, 1, N) {
			if (Q[i] != Q[i - 1]) {
				cout << Q[i] << " ";
			}
			else {
				cout << idx << " ";
				idx++;
				while (use[idx] == 1)
					idx++;
			}
		}
		cout << "\n";
		FOR(i, 1, N)
			Parent[i] = i;
		FOR(i, 1, N) {
			if (use[i]) {
				if (i == 1) continue;
				Union(i, i - 1);
			}
		}
		FOR(i, 1, N) {
			if (Q[i] != Q[i - 1]) {
				cout << Q[i] << " ";
			}
			else {
				int tmp = Find_Parent(Q[i]);
				cout << tmp << " ";
				if (tmp == 1) continue;
				Union(tmp, tmp - 1);
			}
		}
		cout << "\n";
	}

	return 0;
}