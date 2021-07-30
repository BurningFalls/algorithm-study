#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
vector<int> edge[100001];
int depth[100001];
int Parent[100001][20];
int max_level;

void Find_Parent(int cur, int prev) {
	depth[cur] = depth[prev] + 1;
	Parent[cur][0] = prev;
	FOR(i, 1, max_level) {
		int tmp = Parent[cur][i - 1];
		Parent[cur][i] = Parent[tmp][i - 1];
	}
	int len = edge[cur].size();
	FOR(i, 0, len - 1) {
		int next = edge[cur][i];
		if (next == prev) continue;
		Find_Parent(next, cur);
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	depth[0] = -1;
	max_level = (int)floor(log2(100001));
	Find_Parent(1, 0);

	int M;
	cin >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b])
				swap(a, b);
			ROF(i, max_level, 0) {
				if (depth[a] <= depth[Parent[b][i]])
					b = Parent[b][i];
			}
		}
		int lca = a;
		if (a != b) {
			ROF(i, max_level, 0) {
				if (Parent[a][i] != Parent[b][i]) {
					a = Parent[a][i];
					b = Parent[b][i];
				}
				lca = Parent[a][i];
			}
		}
		cout << lca << "\n";
	}


	return 0;
}