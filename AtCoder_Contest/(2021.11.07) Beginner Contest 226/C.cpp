#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

vector<int> Prev[200001];
ll Time[200001];
bool visited[200001] = { 0, };

ll DFS(int node) {
	ll sum = Time[node];
	for (int next : Prev[node]) {
		if (visited[next]) continue;
		visited[next] = 1;
		sum += DFS(next);
	}
	return sum;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int K;
		cin >> Time[i] >> K;
		FOR(j, 1, K) {
			int num;
			cin >> num;
			Prev[i].push_back(num);
		}
	}
	visited[N] = 1;
	cout << DFS(N);

	return 0;
}