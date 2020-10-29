#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
bool visited[26] = { 0, };
string word[51];
int ans = 0;

void DFS(int node, int cnt) {
	if (cnt == K) {
		int temp = 0;
		FOR(i, 1, N) {
			int len = word[i].size();
			bool flag = true;
			FOR(j, 0, len - 1) {
				if (!visited[word[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag)
				temp++;
		}
		ans = max(ans, temp);
		return;
	}
	FOR(i, node, 25) {
		if (visited[i]) continue;
		visited[i] = 1;
		DFS(i + 1, cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		word[i] = "";
		FOR(j, 4, s.size() - 5)
			word[i] += s[j];
	}
	visited['a' - 'a'] = 1;
	visited['c' - 'a'] = 1;
	visited['i' - 'a'] = 1;
	visited['n' - 'a'] = 1;
	visited['t' - 'a'] = 1;
	if (K < 5)
		cout << 0;
	else if (K == 26)
		cout << N;
	else {
		K -= 5;
		DFS(0, 0);
		cout << ans;
	}

	return 0;
}