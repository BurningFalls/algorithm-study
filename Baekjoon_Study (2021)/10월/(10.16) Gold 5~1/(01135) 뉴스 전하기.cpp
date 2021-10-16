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
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int N;
vvi Edge(51, vi());
vi Depth(51, 0);

int DFS(int node, int prev) {
	vector<int> t;
	for (int next : Edge[node]) {
		if (next == prev) continue;
		t.push_back(DFS(next, node));
	}
	sort(ALL(t), greater<int>());
	int maxi = 0;
	FOR(i, 0, LEN(t) - 1) {
		maxi = max(maxi, t[i] + (i + 1));
	}
	return maxi;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		if (i == 0) continue;
		Edge[num].push_back(i);
	}

	cout << DFS(0, -1);

	return 0;
}