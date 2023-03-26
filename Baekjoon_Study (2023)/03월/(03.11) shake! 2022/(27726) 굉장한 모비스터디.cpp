#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 100001

struct NODE {
	int a;
	int b;
	int c;

	bool operator<(const NODE n) const {
		if (a == n.a) {
			if (b == n.b) {
				return c < n.c;
			}
			return b < n.b;
		}
		return a < n.a;
	}
};

int N;
vector<int> M(3);
vector<vector<int>> Parent(3, vector<int>(MAX));

int Find(int idx, int node) {
	if (Parent[idx][node] == node) {
		return node;
	}
	return Parent[idx][node] = Find(idx, Parent[idx][node]);
}

void Union(int idx, int n1, int n2) {
	n1 = Find(idx, n1);
	n2 = Find(idx, n2);
	if (n1 == n2) return;
	Parent[idx][max(n1, n2)] = min(n1, n2);
}

bool compare(vector<int>& v1, vector<int>& v2) {
	return v1[0] < v2[0];
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, 2) {
		cin >> M[i];
	}
	FOR(i, 0, 2) {
		FOR(j, 1, N) {
			Parent[i][j] = j;
		}
	}
	FOR(i, 0, 2) {
		FOR(j, 0, M[i] - 1) {
			int a, b;
			cin >> a >> b;
			Union(i, a, b);
		}
	}

	map<NODE, vector<int>> mp;
	FOR(i, 1, N) {
		NODE n = { Find(0, i), Find(1, i), Find(2, i) };
		mp[n].push_back(i);
	}

	vector<vector<int>> ans;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		vector<int>& t = (*it).second;
		if (LEN(t) < 2) continue;
		sort(ALL(t));
		ans.push_back(t);
	}
	sort(ALL(ans), compare);

	cout << LEN(ans) << "\n";
	FOR(i, 0, LEN(ans) - 1) {
		FOR(j, 0, LEN(ans[i]) - 1) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}