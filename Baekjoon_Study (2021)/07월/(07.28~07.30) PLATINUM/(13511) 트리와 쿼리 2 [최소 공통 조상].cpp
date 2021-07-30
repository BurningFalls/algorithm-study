#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 100001

int N;
vector<pii> edge[MAX];
int depth[MAX];
int Parent[MAX][20];
int max_level;
ll dist[MAX];

void Find_Parent(int cur, int prev, int cost) {
	depth[cur] = depth[prev] + 1;
	Parent[cur][0] = prev;
	dist[cur] = dist[prev] + cost;
	FOR(i, 1, max_level) {
		int tmp = Parent[cur][i - 1];
		Parent[cur][i] = Parent[tmp][i - 1];
	}
	int len = edge[cur].size();
	FOR(i, 0, len - 1) {
		pii next = edge[cur][i];
		if (next.first == prev) continue;
		Find_Parent(next.first, cur, next.second);
	}
}

int LCA(int A, int B) {
	if (depth[A] > depth[B])
		swap(A, B);
	if (depth[A] < depth[B]) {
		ROF(i, max_level, 0) {
			if (depth[A] <= depth[Parent[B][i]]) {
				B = Parent[B][i];
			}
		}
	}
	int lca = A;
	if (A != B) {
		ROF(i, max_level, 0) {
			if (Parent[A][i] != Parent[B][i]) {
				A = Parent[A][i];
				B = Parent[B][i];
			}
			lca = Parent[A][i];
		}
	}
	return lca;
}

int Counting(int A, int B, int K) {
	int lca = LCA(A, B);
	int cnt = 0;
	if (K > depth[A] - depth[lca] + 1) {
		K -= (depth[A] - depth[lca] + 1);
		K = (depth[B] - depth[lca]) - K;
		while (K != 0) {
			if (K % 2 == 1)
				B = Parent[B][cnt];
			K /= 2;
			cnt++;
		}
		return B;
	}
	else {
		K--;
		while (K != 0) {
			if (K % 2 == 1)
				A = Parent[A][cnt];
			K /= 2;
			cnt++;
		}
		return A;
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({ v, w });
		edge[v].push_back({ u, w });
	}

	max_level = (int)floor(log2(MAX));
	depth[0] = -1;
	dist[0] = 0;
	Find_Parent(1, 0, 0);

	int M;
	cin >> M;
	FOR(i, 1, M) {
		int kind, u, v, k;
		cin >> kind;
		if (kind == 1) {
			cin >> u >> v;
			int lca = LCA(u, v);
			cout << dist[u] + dist[v] - 2 * dist[lca];
		}
		else if (kind == 2) {
			cin >> u >> v >> k;
			cout << Counting(u, v, k);
		}
		cout << "\n";
	}


	return 0;
}