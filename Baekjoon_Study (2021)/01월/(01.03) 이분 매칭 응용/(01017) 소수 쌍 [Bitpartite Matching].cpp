#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 500

int N;
int num[MAX];
int wanted[MAX][MAX] = { 0, };
bool is_Prime[2001] = { 0, };
bool visited[MAX] = { 0, };
int bmatch[MAX] = { 0 };

bool Prime_Check(int x) {
	if (x == 2)
		return true;
	FOR(i, 2, sqrt(x)) {
		if (x % i == 0)
			return false;
	}
	return true;
}

bool DFS(int a) {
	if (visited[a])
		return false;
	visited[a] = 1;
	FOR(b, 1, N) {
		if (!wanted[a][b]) continue;
		if (bmatch[b] == 0 || DFS(bmatch[b])) {
			bmatch[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	FASTIO;
	FOR(i, 2, 2000)
		is_Prime[i] = Prime_Check(i);
	cin >> N;
	FOR(i, 1, N)
		cin >> num[i];
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			if (is_Prime[num[i] + num[j]]) {
				wanted[i][j] = 1;
				wanted[j][i] = 1;
			}
		}
	}

	vector<int> ans_v;
	FOR(i, 2, N) {
		memset(bmatch, 0, sizeof(bmatch));
		if (!wanted[1][i]) continue;
		int ans = 1;
		bmatch[i] = 1;
		FOR(j, 2, N) {
			memset(visited, 0, sizeof(visited));
			visited[1] = 1;
			if (DFS(j))
				ans++;
		}
		if (ans == N)
			ans_v.push_back(num[i]);
	}
	if (ans_v.empty())
		cout << -1;
	else {
		sort(ans_v.begin(), ans_v.end());
		for (auto node : ans_v)
			cout << node << " ";
	}

	return 0;
}