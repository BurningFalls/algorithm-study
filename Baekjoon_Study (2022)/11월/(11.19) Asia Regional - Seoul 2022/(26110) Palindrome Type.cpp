#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int DFS(string& s, int left, int right, int cnt) {
	if (cnt > 3) {
		return INF;
	}
	if (left >= right) {
		return 0;
	}
	if (s[left] == s[right]) {
		return DFS(s, left + 1, right - 1, cnt);
	}
	else if (s[left] != s[right]) {
		int a = DFS(s, left + 1, right, cnt + 1);
		int b = DFS(s, left, right - 1, cnt + 1);
		return min(a, b) + 1;
	}
}

int main() {
	FASTIO;
	string s;
	cin >> s;
	int ans = DFS(s, 0, LEN(s) - 1, 0);
	cout << (ans >= INF ? -1 : ans);

	return 0;
}