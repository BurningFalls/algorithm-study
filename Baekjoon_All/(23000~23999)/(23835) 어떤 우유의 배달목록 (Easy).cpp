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

int N, Q;
vector<vector<int>> Edge(1001, vector<int>());
vector<int> Route(1001, 0);
vector<int> Milk(1001, 0);

bool DFS(int node, int prev, int goal, int cnt) {
	Route[cnt] = node;
	if (node == goal) {
		FOR(i, 1, cnt) {
			Milk[Route[i]] += i;
		}
		return true;
	}
	bool flag = false;
	for (int next : Edge[node]) {
		if (next == prev) continue;
		flag |= DFS(next, node, goal, cnt + 1);
		if (flag) {
			break;
		}
	}
	return flag;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	cin >> Q;
	FOR(q, 1, Q) {
		int k, a, b;
		cin >> k;
		if (k == 1) {
			cin >> a >> b;
			DFS(a, 0, b, 0);
		}
		else if (k == 2) {
			cin >> a;
			cout << Milk[a] << "\n";
		}
	}


	return 0;
}