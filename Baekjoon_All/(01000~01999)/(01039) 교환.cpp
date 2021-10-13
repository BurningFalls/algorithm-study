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

vvi visited(1000001, vi(2, -1));

int BFS(int N, int K) {
	queue<pii> q;
	q.push({ N, 0 });
	visited[N][0] = 0;
	while (!q.empty()) {
		int node = q.front().first;
		int vis = q.front().second;
		q.pop();
		if (vis > K)
			break;
		string s = to_string(node);
		int len = LEN(s);
		FOR(i, 0, len - 1) {
			FOR(j, i + 1, len - 1) {
				if (i == 0 && s[j] == '0') continue;
				string ns = s;
				swap(ns[i], ns[j]);
				int next = stoi(ns);
				int nvis = vis + 1;
				if (visited[next][nvis % 2] != -1) continue;
				visited[next][nvis % 2] = nvis;
				q.push({ next, nvis });
			}
		}
	}

	ROF(i, 1000000, 1) {
		if (visited[i][K % 2] != -1) {
			return i;
		}
	}
	return -1;
}

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	if (N < 10 || (N < 100 && N % 10 == 0)) {
		cout << -1;
		return 0;
	}

	cout << BFS(N, K);

	return 0;
}