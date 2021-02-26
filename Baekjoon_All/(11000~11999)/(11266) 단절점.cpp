#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MAX 10000 + 1

int V, E;
vector<int> edge[MAX];
int discovered[MAX];
bool isCutVertex[MAX] = { 0, };
int counter = 0;

int DFS(int node, bool isRoot) {
	discovered[node] = ++counter;
	int ret = discovered[node];
	int child = 0;
	for (int next : edge[node]) {
		if (!discovered[next]) {
			child++;
			int low = DFS(next, false);
			if (!isRoot && low >= discovered[node])
				isCutVertex[node] = true;
			ret = min(ret, low);
		}
		else {
			ret = min(ret, discovered[next]);
		}
	}

	if (isRoot)
		isCutVertex[node] = (child >= 2);
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
	FOR(i, 1, V) {
		if (discovered[i]) continue;
		DFS(i, true);
	}
	int cnt = 0;
	FOR(i, 1, V) {
		if (!isCutVertex[i]) continue;
		cnt++;
	}
	cout << cnt << "\n";
	FOR(i, 1, V) {
		if (!isCutVertex[i]) continue;
		cout << i << " ";
	}

	return 0;
}