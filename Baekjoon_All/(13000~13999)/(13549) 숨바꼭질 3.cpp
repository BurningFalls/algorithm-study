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
	int N, K;
	vector<int> visited(100001, 0);
	cin >> N >> K;
	queue<int> q;
	visited[N] = 1;
	q.push(N);
	
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node == K) break;
		int next = node * 2;
		while (next != 0 && next <= 100000) {
			if (!visited[next]) {
				visited[next] = visited[node];
				q.push(next);
			}
			next *= 2;
		}
		if (node >= 1 && !visited[node - 1]) {
			visited[node - 1] = visited[node] + 1;
			q.push(node - 1);
		}
		if (node < 100000 && !visited[node + 1]) {
			visited[node + 1] = visited[node] + 1;
			q.push(node + 1);
		}
	}
	cout << visited[K] - 1;

	return 0;
}