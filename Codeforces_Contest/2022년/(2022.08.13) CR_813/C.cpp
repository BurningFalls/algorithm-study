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

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> v(N);
		vector<bool> visited(N, 0);
		vector<vector<int>> pos(N + 1, vector<int>());
		FOR(i, 0, N - 1) {
			cin >> v[i];
			pos[v[i]].push_back(i);
		}
		int idx = -1;
		ROF(i, N - 2, 0) {
			if (v[i] > v[i + 1]) {
				idx = i;
				break;
			}
		}
		FOR(i, 0, idx) {
			if (visited[i]) continue;
			visited[i] = 1;
			for (int next : pos[v[i]]) {
				visited[next] = 1;
			}
		}
		idx = -1;
		ROF(i, N - 1, 0) {
			if (visited[i]) {
				idx = i;
				break;
			}
		}
		set<int> s;
		FOR(i, 0, idx) {
			s.insert(v[i]);
		}
		cout << s.size() << "\n";
	}

	return 0;
}