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

vector<vector<int>> Edge(100001, vector<int>());
vector<bool> visited(100001, 0);
bool flag = false;
int n1 = 0, n2 = 0;

ll DFS(int node) {
	if (node == n2) {
		flag = true;
	}
	ll cnt = 1;
	for (int next : Edge[node]) {
		if (visited[next]) continue;
		visited[next] = 1;
		cnt += DFS(next);
	}
	return cnt;
}

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	FOR(m, 1, M) {
		int a, b;
		cin >> a >> b;
		if (m == K) {
			n1 = a;
			n2 = b;
		}
		else {
			Edge[a].push_back(b);
			Edge[b].push_back(a);
		}
	}
	visited[n1] = 1;
	ll tmp1 = DFS(n1);
	if (flag) {
		cout << 0;
		return 0;
	}
	visited[n2] = 1;
	ll tmp2 = DFS(n2);
	cout << tmp1 * tmp2;

	return 0;
}