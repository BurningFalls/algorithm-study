#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int dp[120][6];
int Move[6] = { 1, -1, 10, -10, 60 };
int scoring[6][6] = { {0, 0, 0, 1, 0},
{0, 0, 0, 0, 1},
{0, 1, 0, 0, 0 },
{0, 0, 1, 0, 0},
{1, 0, 0, 0, 0} };

bool Check(int arr1[5], int arr2[5], int idx) {
	int new_arr[5];
	new_arr[0] = arr2[0] + scoring[idx][0];
	new_arr[1] = arr2[1] + scoring[idx][1];
	new_arr[2] = arr2[2] + scoring[idx][2];
	new_arr[3] = arr2[3] + scoring[idx][3];
	new_arr[4] = arr2[4] + scoring[idx][4];
	FOR(i, 0, 4) {
		if (arr1[i] > new_arr[i])
			return true;
		else if (arr1[i] < new_arr[i])
			return false;
	}
	return true;
}

void Func(int n) {
	bool flag = false;
	FOR(i, 0, 5) {
		int next = n + Move[i];
		if (next < 0 || next > 119) continue;
		if ((dp[next][5] == dp[n][5] + 1 && Check(dp[next], dp[n], i)) ||
			(dp[next][5] > dp[n][5] + 1)) {
			dp[next][0] = dp[n][0] + scoring[i][0];
			dp[next][1] = dp[n][1] + scoring[i][1];
			dp[next][2] = dp[n][2] + scoring[i][2];
			dp[next][3] = dp[n][3] + scoring[i][3];
			dp[next][4] = dp[n][4] + scoring[i][4];
			dp[next][5] = dp[n][5] + 1;
			Func(next);
			flag = true;
		}
	}
	if (!flag)
		return;
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	FOR(i, 0, 119) {
		dp[i][0] = 0;
		dp[i][1] = 0;
		dp[i][2] = 0;
		dp[i][3] = i;
		dp[i][4] = 0;
		dp[i][5] = i;
	}
	Func(0);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int tmp = N % 120;
		N /= 120;
		cout << dp[tmp][0] + N * 2 << " ";
		FOR(i, 1, 4)
			cout << dp[tmp][i] << " ";
		cout << "\n";
	}
	

	return 0;
}