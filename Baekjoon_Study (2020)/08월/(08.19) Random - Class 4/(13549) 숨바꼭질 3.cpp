#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, K;
bool visited[100001] = { 0, };
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int BFS() {
	pq.push(make_pair(1, N));
	visited[N] = 1;
	while (!pq.empty()) {
		int t = pq.top().first;
		int n = pq.top().second;
		pq.pop();
		if (n == K)
			return t - 1;
		if (n * 2 <= 100000 && !visited[n * 2]) {
			visited[n * 2] = 1;
			pq.push(make_pair(t, n * 2));
		}
		if (n + 1 <= 100000 && !visited[n + 1]) {
			visited[n + 1] = 1;
			pq.push(make_pair(t + 1, n + 1));
		}
		if (n - 1 >= 0 && !visited[n - 1]) {
			visited[n - 1] = 1;
			pq.push(make_pair(t + 1, n - 1));
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	cout << BFS();

	return 0;
}