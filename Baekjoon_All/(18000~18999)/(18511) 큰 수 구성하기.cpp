#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
int num[3];
string s;
int ans[11] = { 0, };
bool flag = false;

void DFS(int node, int end) {
	if (node >= end) {
		FOR(i, 0, 10) {
			if (ans[i] != 0)
				cout << ans[i];
		}
		exit(0);
	}
	if (flag) {
		ans[node] = num[0];
		DFS(node + 1, end);
		return;
	}
	FOR(i, 0, K - 1) {
		if (s[node] - '0' >= num[i]) {
			ans[node] = num[i];
			if (s[node] - '0' != num[i])
				flag = true;
			DFS(node + 1, end);
		}
	}
	if (node == 0) {
		ans[node] = 0;
		flag = true;
		DFS(node + 1, end);
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	s = to_string(N);
	int len = s.size();
	FOR(i, 0, K - 1)
		cin >> num[i];
	sort(num, num + K, greater<int>());

	DFS(0, len);

	return 0;
}