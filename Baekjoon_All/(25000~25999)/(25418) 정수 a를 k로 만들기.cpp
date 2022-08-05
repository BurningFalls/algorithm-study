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

vector<int> visited(1000001, 0);

int main() {
	FASTIO;
	int A, K;
	cin >> A >> K;

	queue<int> q;
	q.push(A);
	visited[A] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node == K) {
			break;
		}
		if (node + 1 <= K && !visited[node + 1]) {
			visited[node + 1] = visited[node] + 1;
			q.push(node + 1);
		}
		if (node * 2 <= K && !visited[node * 2]) {
			visited[node * 2] = visited[node] + 1;
			q.push(node * 2);
		}
	}
	cout << visited[K] - 1;

	return 0;
}