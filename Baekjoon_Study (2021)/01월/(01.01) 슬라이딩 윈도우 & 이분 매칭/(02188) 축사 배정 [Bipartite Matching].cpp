#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int wanted[201][201] = { 0, };
int A_match[201];
int B_match[201];
bool visited[201];

bool DFS(int a) {
	if (visited[a])
		return false;
	visited[a] = 1;
	for (int b = 1; b <= M; b++) {
		if (!wanted[a][b]) continue;
		if (B_match[b] == -1 || DFS(B_match[b])) {
			A_match[a] = b;
			B_match[b] = a;
			return true;
		}
	}
	return false;
}

int BM() {
	int ans = 0;
	FOR(i, 1, N) {
		memset(visited, 0, sizeof(visited));
		if (DFS(i))
			ans++;
	}
	return ans;
}

int main() {
	FASTIO;
	memset(A_match, -1, sizeof(A_match));
	memset(B_match, -1, sizeof(B_match));
	cin >> N >> M;
	FOR(i, 1, N) {
		int cnt;
		cin >> cnt;
		FOR(j, 1, cnt) {
			int num;
			cin >> num;
			wanted[i][num] = 1;
		}
	}

	cout << BM();

	return 0;
}