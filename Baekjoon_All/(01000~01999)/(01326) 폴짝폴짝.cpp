#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, A, B;
int arr[10001];
int visited[10001] = { 0, };

int BFS() {
	if (A == B)
		return 1;
	if (abs(B - A) % arr[A] == 0)
		return 2;
	queue<int> q;
	q.push(A);
	visited[A] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = node + arr[node]; i <= N; i += arr[node]) {
			if (visited[i]) continue;
			if (i == B)
				return visited[node] + 1;
			if (abs(B - i) % arr[i] == 0)
				return visited[node] + 2;
			visited[i] = visited[node] + 1;
			q.push(i);
		}
		for (int i = node - arr[node]; i >= 1; i -= arr[node]) {
			if (visited[i]) continue;
			if (i == B)
				return visited[node] + 1;
			if (abs(B - i) % arr[i] == 0)
				return visited[node] + 2;
			visited[i] = visited[node] + 1;
			q.push(i);
		}
	}
	return 0;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	cin >> A >> B;
	cout << BFS() - 1;

	return 0;
}