#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

string s;
int len;
int ans = -INF;
int dp[200001][2];

// flag = 0->숫자 / 1->기호
// 0 -> 더하기 / 1 -> 빼기
pii DFS(int idx, bool flag) {
	if (idx == -1) {
		if (flag == 0) {
			return { -INF + 1, -1 };
		}
		else if (flag == 1) {
			return { 0, 0 };
		}
	}
	int& ret = dp[idx][flag];
	if (ret != -INF) {
		if (flag == 0) {
			return { ret, -1 };
		}
		else if (s[idx] == '+') {
			return { ret, 0 };
		}
		else if (s[idx] == '-') {
			return { ret, 1 };
		}
	}
	ret = -INF + 1;
	if (flag == 0) {
		if (s[idx] == '+') {
			pii tmp = DFS(idx - 1, 1);
			if (tmp.second == 0) {
				ret = max(ret, tmp.first + 10);
			}
			else if (tmp.second == 1) {
				ret = max(ret, tmp.first - 10);
			}
		}
		if (idx != 0 && s[idx] == '-' && s[idx - 1] == '+') {
			pii tmp = DFS(idx - 2, 1);
			if (tmp.second == 0) {
				ret = max(ret, tmp.first + 11);
			}
			else if (tmp.second == 1) {
				ret = max(ret, tmp.first - 11);
			}
		}
		if (s[idx] == '-') {
			pii tmp = DFS(idx - 1, 1);
			if (tmp.second == 0) {
				ret = max(ret, tmp.first + 1);
			}
			else if (tmp.second == 1) {
				ret = max(ret, tmp.first - 1);
			}
		}
		return { ret, -1 };
	}
	else if (flag == 1) {
		if (s[idx] == '+') {
			pii tmp = DFS(idx - 1, 0);
			ret = tmp.first;
			return { ret, 0 };
		}
		if (s[idx] == '-') {
			pii tmp = DFS(idx - 1, 0);
			ret = tmp.first;
			return { ret, 1 };
		}
	}
}

int main() {
	FASTIO;
	cin >> s;
	len = LEN(s);
	FOR(i, 0, len - 1) {
		FOR(j, 0, 1) {
			dp[i][j] = -INF;
		}
	}
	pii tmp = DFS(len - 1, 0);
	cout << tmp.first;

	return 0;
}