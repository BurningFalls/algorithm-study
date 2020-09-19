#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M;
vector<int> v[100001];
int Parent[100001][19];
int d[100001] = { 0, };

void DFS(int n, int depth) {
	d[n] = depth;
	int len = v[n].size();
	FOR(i, 0, len - 1) {
		int nn = v[n][i];
		if (d[nn]) continue;
		Parent[nn][0] = n;
		DFS(nn, depth + 1);
	}
}

void Make_Parent() {
	FOR(j, 1, 18) {
		FOR(i, 1, N) {
			Parent[i][j] = Parent[Parent[i][j - 1]][j - 1];
		}
	}
}

int Find(int n1, int n2) {
	if (d[n2] < d[n1])
		swap(n2, n1);
	ROF(i, 18, 0) {
		int dif = d[n2] - d[n1];
		if (dif >= (1 << i))
			n2 = Parent[n2][i];
	}
	if (n2 == n1)
		return n2;
	ROF(i, 18, 0) {
		if (Parent[n2][i] != Parent[n1][i]) {
			n2 = Parent[n2][i];
			n1 = Parent[n1][i];
		}
	}
	return Parent[n2][0];
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N - 1) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(1, 1);
	Make_Parent();
	cin >> M;
	FOR(i, 1, M) {
		int x, y;
		cin >> x >> y;
		cout << Find(x, y) << "\n";
	}

	return 0;
}