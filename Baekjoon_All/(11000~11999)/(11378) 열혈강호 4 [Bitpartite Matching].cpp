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
bool visited[MAX];
int bmatch[MAX];

bool DFS(int a) {
	if (visited[a])
		return false;
	visited[a] = 1;
	for (auto b : wanted[a]) {
		if (bmatch[b] == -1 || DFS(bmatch[b])) {
			bmatch[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	FASTIO;
	memset(bmatch, -1, sizeof(bmatch));
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

	int ans = 0;
	FOR(i, 1, N) {
		memset(visited, 0, sizeof(visited));
		if (DFS(i))
			ans++;
	}
	bool flag;
	while (K > 0) {
		flag = false;
		FOR(i, 1, N) {
			memset(visited, 0, sizeof(visited));
			if (DFS(i)) {
				ans++;
				K--;
				flag = true;
				break;
			}
		}
		if (!flag)
			break;
	}
	cout << ans;

	return 0;
}