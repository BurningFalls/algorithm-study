#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000 + 1

int N, M;
vector<int> wanted[MAX];
bool visited[MAX];
int B_match[MAX];

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
	FOR(i, 1, N) {
		int cnt;
		cin >> cnt;
		FOR(j, 1, cnt) {
			int num;
			cin >> num;
			wanted[i].push_back(num);
		}
	}

	cout << BM();

	return 0;
}