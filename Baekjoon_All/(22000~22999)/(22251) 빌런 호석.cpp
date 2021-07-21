#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	bool num[10][7] = {
	{1, 1, 1, 0, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 0},
	{1, 0, 1, 1, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1},
	{0, 1, 1, 1, 0, 1, 0},
	{1, 1, 0, 1, 0, 1, 1},
	{1, 1, 0, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 1, 0},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1}
	};
	
	int ch[10][10];
	FOR(i, 0, 9) {
		FOR(j, 0, 9) {
			int cnt = 0;
			FOR(k, 0, 6) {
				if (num[i][k] != num[j][k])
					cnt++;
			}
			ch[i][j] = cnt;
		}
	}

	int N, K, P, X;
	cin >> N >> K >> P >> X;

	int start_num[7] = { 0, };
	int end_num[7] = { 0, };
	string str_x = to_string(X);
	int xlen = str_x.size();
	FOR(i, K - xlen, K - 1) {
		start_num[i] = str_x[i - (K - xlen)] - '0';
	}
	int ans = 0;
	FOR(goal, 1, N) {
		string str_goal = to_string(goal);
		int goal_len = str_goal.size();
		FOR(i, K - goal_len, K - 1) {
			end_num[i] = str_goal[i - (K - goal_len)] - '0';
		}
		int sum = 0;
		FOR(i, 0, K - 1) {
			sum += ch[start_num[i]][end_num[i]];
		}
		if (sum <= P) {
			ans++;
		}
	}
	cout << ans - 1;


	return 0;
}