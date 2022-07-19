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

int N;
vector<int> dp((1 << 20), -1);
vector<int> ch(20);

int BFS(int start) {
	queue<int> q;
	q.push(start);
	dp[start] = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node == (1 << N) - 1) break;
		FOR(i, 0, N - 1) {
			if (node & (1 << i)) continue;
			int next = node ^ ch[i];
			if (dp[next] != -1) continue;
			dp[next] = dp[node] + 1;
			q.push(next);
		}
	}
	return dp[(1 << N) - 1];
}

int main() {
	FASTIO;
	cin >> N;
	int start = 0;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		if (num == 1) {
			start |= (1 << i);
		}
	}
	FOR(i, 0, N - 1) {
		ch[i] = (1 << i);
		int C;
		cin >> C;
		FOR(j, 0, C - 1) {
			int num;
			cin >> num;
			ch[i] |= (1 << (num - 1));
		}
	}

	cout << BFS(start);

	return 0;
}