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
		vector<int> num(N + 1);
		vector<int> indegree(N + 1, 0);
		FOR(i, 1, N) {
			cin >> num[i];
			indegree[num[i]]++;
		}
		queue<int> q;
		FOR(i, 1, N) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		int cnt = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cnt++;
			int next = num[node];
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}