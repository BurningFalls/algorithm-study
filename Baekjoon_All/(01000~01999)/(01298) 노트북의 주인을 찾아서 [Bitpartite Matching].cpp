#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
vector<int> wanted[101];
int B_match[101];
bool visited[101] = { 0, };

bool DFS(int a) {
	int len = wanted[a].size();
	FOR(i, 0, len - 1) {
		int b = wanted[a][i];
		if (visited[b]) continue;
		visited[b] = 1;
		if (B_match[b] == -1 || DFS(B_match[b])) {
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
	memset(B_match, -1, sizeof(B_match));
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		wanted[a].push_back(b);
	}

	cout << BM();

	return 0;
}