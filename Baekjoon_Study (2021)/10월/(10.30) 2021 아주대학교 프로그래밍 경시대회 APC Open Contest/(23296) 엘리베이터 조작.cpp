#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N;
int Next[100001];
int indegree[100001] = { 0, };
bool visited[100001] = { 0, };
vector<int> ans;

void DFS(int node) {
	if (visited[node]) {
		ans.push_back(node);
		return;
	}
	visited[node] = 1;
	ans.push_back(node);
	DFS(Next[node]);
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> Next[i];
		indegree[Next[i]]++;
	}
	visited[1] = 1;
	DFS(Next[1]);
	FOR(i, 1, N) {
		if (visited[i]) continue;
		if (indegree[i] == 0) {
			ans.push_back(i);
			visited[i] = 1;
			DFS(Next[i]);
		}
	}
	FOR(i, 1, N) {
		if (visited[i]) continue;
		if (indegree[i] == 1) {
			ans.push_back(i);
			visited[i] = 1;
			DFS(Next[i]);
		}
	}
	cout << LEN(ans) << "\n";
	for (int x : ans) {
		cout << x << " ";
	}

	return 0;
}