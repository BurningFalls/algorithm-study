#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string S;
set<string> se;
int possible[101][101] = { 0, };
int Slen;
bool flag = false;
int dp[101] = { 0, };

void DFS(int start) {
	if (start >= Slen) {
		flag = true;
		return;
	}
	FOR(end, start, Slen - 1) {
		if (flag)
			return;
		if (possible[start][end]) {
			if (dp[end]) continue;
			dp[end] = 1;
			DFS(end + 1);
		}
	}
}

int main() {
	FASTIO;
	cin >> S;
	Slen = S.size();
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		se.insert(s);
	}
	string tmp;
	FOR(start, 0, Slen - 1) {
		tmp = "";
		FOR(end, start, Slen - 1) {
			tmp += S[end];
			if (se.count(tmp))
				possible[start][end] = 1;
		}
	}
	DFS(0);
	cout << flag;

	return 0;
}