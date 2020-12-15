#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int A, B, N, M;
int visited[100001] = { 0, };

int BFS() {
	if (N == M)
		return 1;
	queue<int> q;
	q.push(N);
	visited[N] = 1;
	int arr[8];
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		arr[0] = node + 1;
		arr[1] = node - 1;
		arr[2] = node + A;
		arr[3] = node - A;
		arr[4] = node + B;
		arr[5] = node - B;
		arr[6] = node * A;
		arr[7] = node * B;
		FOR(i, 0, 7) {
			if (arr[i] < 0 || arr[i] > 100000) continue;
			if (visited[arr[i]]) continue;
			visited[arr[i]] = visited[node] + 1;
			if (arr[i] == M)
				return visited[arr[i]];
			q.push(arr[i]);
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> A >> B >> N >> M;
	cout << BFS() - 1;

	return 0;
}