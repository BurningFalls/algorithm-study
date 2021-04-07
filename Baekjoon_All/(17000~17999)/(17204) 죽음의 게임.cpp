#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int A[151];
int visited[151] = { 0, };

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 0, N - 1)
		cin >> A[i];
	visited[0] = 1;
	int cur = 0;
	while (true) {
		int next = A[cur];
		if (visited[next])
			break;
		visited[next] = visited[cur] + 1;
		cur = next;
	}
	cout << visited[K] - 1;


	return 0;
}