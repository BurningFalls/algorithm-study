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

vector<vector<int>> v(11, vector<int>(11));
vector<bool> visited(11, 0);
int maxi;

void DFS(int node, int sum) {
	if (node == 11) {
		maxi = max(maxi, sum);
		return;
	}
	FOR(i, 0, 10) {
		if (v[node][i] == 0) continue;
		if (visited[i]) continue;
		visited[i] = 1;
		DFS(node + 1, sum + v[node][i]);
		visited[i] = 0;
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		maxi = 0;
		FOR(i, 0, 10) {
			FOR(j, 0, 10) {
				cin >> v[i][j];
			}
		}
		DFS(0, 0);
		cout << maxi << "\n";
	}

	return 0;
}