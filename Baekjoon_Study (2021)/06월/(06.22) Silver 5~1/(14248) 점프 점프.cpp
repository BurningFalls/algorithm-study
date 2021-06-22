#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int A[100001];
bool visited[100001] = { 0, };
int cnt = 0;

void DFS(int node) {
	visited[node] = 1;
	cnt++;
	if (node - A[node] >= 1 && !visited[node - A[node]])
		DFS(node - A[node]);
	if (node + A[node] <= N && !visited[node + A[node]])
		DFS(node + A[node]);
}

int main() {
	FASTIO;
	int s;
	cin >> N;
	FOR(i, 1, N)
		cin >> A[i];
	cin >> s;
	DFS(s);
	cout << cnt;

	return 0;
}