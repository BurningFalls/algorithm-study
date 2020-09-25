#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 10000 + 1

int V, E;
vector<int> v[MAX];
int visited[MAX] = { 0, };
bool finished[MAX] = { 0, };
int sn[MAX] = { 0, };
vector<int> s;
int idx = 1;
int ans = 0;
vector<vector<int>> ans_v;

int DFS(int node) {
	visited[node] = idx;
	idx += 1;
	s.push_back(node);
	int len = v[node].size();
	int minimum = visited[node];
	FOR(i, 0, len - 1) {
		int nn = v[node][i];
		if (!visited[nn]) {
			minimum = min(minimum, DFS(nn));
		}
		else if (visited[nn] && !finished[nn]) {
			minimum = min(minimum, visited[nn]);
		}
	}

	if (minimum == visited[node]) {
		vector<int> ss;
		while (true) {
			int t = s.back();
			s.pop_back();
			ss.push_back(t);
			finished[t] = 1;
			sn[t] = ans;
			if (t == node)
				break;
		}
		sort(ss.begin(), ss.end());
		ans_v.push_back(ss);
		ans++;
	}
	return minimum;
}

int main() {
	FASTIO;
	cin >> V >> E;
	FOR(i, 1, E) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
	}
	FOR(i, 1, V) {
		if (visited[i]) continue;
		DFS(i);
	}
	sort(ans_v.begin(), ans_v.end());
	cout << ans << "\n";
	FOR(i, 0, ans_v.size() - 1) {
		FOR(j, 0, ans_v[i].size() - 1) {
			cout << ans_v[i][j] << " ";
		}
		cout << "-1\n";
	}

	return 0;
}