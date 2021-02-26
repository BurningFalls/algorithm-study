#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MAX 100000 + 1

int V, E;
vector<int> edge[MAX];
int discovered[MAX];
bool isCutVertex[MAX] = { 0, };
int counter = 0;
vector<pii> v;

int DFS(int node, int parent) {
	discovered[node] = ++counter;
	int ret = discovered[node];
	for (int next : edge[node]) {
		if (next == parent) continue;
		if (!discovered[next]) {
			int low = DFS(next, node);
			if (low > discovered[node])
				v.push_back({min(node, next), max(node, next)});
			ret = min(ret, low);
		}
		else {
			ret = min(ret, discovered[next]);
		}
	}
	return ret;
}

int main() {
	FASTIO;
	cin >> V >> E;
	FOR(i, 1, E) {
		int A, B;
		cin >> A >> B;
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	DFS(1, 0);
	sort(v.begin(), v.end());
	int len = v.size();
	cout << len << "\n";
	for (pii x : v) {
		cout << x.first << " " << x.second << "\n";
	}

	return 0;
}