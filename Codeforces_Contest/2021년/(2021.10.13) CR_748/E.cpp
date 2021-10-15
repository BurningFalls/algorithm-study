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

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<int> connect(N + 1, 0);
		vector<vector<int>> edge(N + 1);
		vector<int> nouse(N + 1, 0);
		FOR(i, 1, N - 1) {
			int a, b;
			cin >> a >> b;
			connect[a]++;
			connect[b]++;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		if (N == 1) {
			cout << "0\n";
			continue;
		}
		int ans = N;
		queue<pii> q;
		FOR(i, 1, N) {
			if (--connect[i] == 0) {
				nouse[i] = 1;
				ans--;
				q.push({ i, 1 });
			}
		}
		while (!q.empty()) {
			int node = q.front().first;
			int cnt = q.front().second;
			q.pop();
			if (cnt == K)
				break;
			for (int next : edge[node]) {
				if (nouse[next]) continue;
				if (--connect[next] == 0) {
					nouse[next] = 1;
					ans--;
					q.push({ next, cnt + 1 });
				}
			}
		}
		P1(ans);
	}


	return 0;
}