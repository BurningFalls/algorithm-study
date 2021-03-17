#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

vector<int> v1, v2;
int dp[16][16][1001];
int cnt = 0;

int DP(int w, int b, int idx) {
	if (w == 15 && b == 15)
		return 0;
	if (idx == cnt)
		return 0;
	int& ret = dp[w][b][idx];
	if (ret != -1)
		return ret;
	ret = 0;
	if (w < 15)
		ret = max(ret, DP(w + 1, b, idx + 1) + v1[idx]);
	if (b < 15)
		ret = max(ret, DP(w, b + 1, idx + 1) + v2[idx]);
	ret = max(ret, DP(w, b, idx + 1));
	return ret;
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	int white, black;
	while (cin >> white >> black) {
		v1.push_back(white);
		v2.push_back(black);
		cnt++;
	}
	cout << DP(0, 0, 0);

	return 0;
}