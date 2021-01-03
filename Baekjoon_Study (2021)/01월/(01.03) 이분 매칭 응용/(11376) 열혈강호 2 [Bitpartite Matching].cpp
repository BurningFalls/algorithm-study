#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
vector<int> wanted[1001];
bool visited[1001] = { 0, };
int B_match[1001];

bool DFS(int a) {
	if (visited[a])
		return false;
	visited[a] = 1;
	int len = wanted[a].size();
	FOR(i, 0, len - 1) {
		int b = wanted[a][i];
		if (B_match[b] == -1 || DFS(B_match[b])) {
			B_match[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	FASTIO;
	memset(B_match, -1, sizeof(B_match));
	cin >> N >> M;
	FOR(i, 1, N) {
		int cnt;
		cin >> cnt;
		FOR(j, 1, cnt) {
			int num;
			cin >> num;
			wanted[i].push_back(num);
		}
	}

	int ans = 0;
	FOR(i, 1, N) {
		FOR(j, 1, 2) {
			memset(visited, 0, sizeof(visited));
			if (DFS(i))
				ans++;
		}
	}
	cout << ans;

	return 0;
}