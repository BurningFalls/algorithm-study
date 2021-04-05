#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string s;
int len;
int top = 1;
bool visited[101] = { 0, };
int ans[101];

void DFS(int node, int cnt) {
	if (cnt >= len || node > top) {
		FOR(i, 1, top)
			cout << ans[i] << " ";
		exit(0);
		return;
	}
	int a = -1, b = -1;
	if (cnt <= len - 2)
		a = (s[cnt] - '0') * 10 + (s[cnt + 1] - '0');
	b = s[cnt] - '0';
	if (a != -1 && a <= top && !visited[a]) {
		visited[a] = 1;
		ans[node] = a;
		DFS(node + 1, cnt + 2);
		visited[a] = 0;
	}
	if (b <= top && !visited[b]) {
		visited[b] = 1;
		ans[node] = b;
		DFS(node + 1, cnt + 1);
		visited[b] = 0;
	}
}

int main() {
	FASTIO;
	cin >> s;
	len = s.size();
	if (len <= 9)
		top = len;
	else 
		top = (len - 9) / 2 + 9;

	DFS(1, 0);


	return 0;
}