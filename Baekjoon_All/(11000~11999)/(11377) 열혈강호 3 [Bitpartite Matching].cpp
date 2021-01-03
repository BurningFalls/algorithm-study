#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000 + 1

int N, M, K;
vector<int> wanted[MAX];
int B_match[MAX] = { 0, };
bool visited[MAX] = { 0, };
int ans = 0;

bool DFS(int a) {
	if (visited[a])
		return false;
	visited[a] = 1;
	for (auto b : wanted[a]) {
		if (B_match[b] == 0 || DFS(B_match[b])) {
			B_match[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, N) {
		int cnt;
		cin >> cnt;
		FOR(j, 1, cnt) {
			int num;
			cin >> num;
			wanted[i].push_back(num);
		}
	}

	FOR(i, 1, N) {
		memset(visited, 0, sizeof(visited));
		if (DFS(i))
			ans++;
	}
	FOR(i, 1, N) {
		memset(visited, 0, sizeof(visited));
		if (DFS(i)) {
			ans++;
			K--;
			if (K == 0)
				break;
		}
	}
	cout << ans;

	return 0;
}