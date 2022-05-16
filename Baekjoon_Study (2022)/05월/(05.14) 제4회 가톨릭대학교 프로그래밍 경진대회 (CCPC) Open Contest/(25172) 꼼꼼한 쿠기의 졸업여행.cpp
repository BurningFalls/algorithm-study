#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MAX 200001

vector<int> Parent(MAX);

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
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		Parent[i] = i;
	}
	vector<vector<int>> Edge(N + 1, vector<int>());
	vector<int> Erase(N);
	vector<int> Exist(N + 1, 0);
	vector<int> ans;
	FOR(m, 1, M) {
		int a, b;
		cin >> a >> b;
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	FOR(n, 0, N - 1) {
		cin >> Erase[n];
	}

	int group_cnt = 0;
	ans.push_back(0);
	ROF(i, N - 1, 0) {
		int node = Erase[i];
		Exist[node] = 1;
		group_cnt++;
		for (int x : Edge[node]) {
			if (!Exist[x]) continue;
			if (!is_Same(node, x)) {
				Union(node, x);
				group_cnt--;
			}
		}
		ans.push_back(group_cnt == 1);
	}

	ROF(i, LEN(ans) - 1, 0) {
		cout << (ans[i] ? "CONNECT" : "DISCONNECT") << "\n";
	}

	return 0;
}