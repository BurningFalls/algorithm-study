#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
int A[9];
bool visited[9] = { 0, };
int Cnt = 0;

void DFS(int weight, int cnt) {
	if (cnt == N) {
		Cnt++;
		return;
	}
	FOR(i, 1, N) {
		if (visited[i]) continue;
		if (weight + A[i] - K < 500)
			break;
		visited[i] = 1;
		DFS(weight + A[i] - K, cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> A[i];
	sort(A + 1, A + N + 1, greater<int>());
	DFS(500, 0);
	cout << Cnt;

	return 0;
}