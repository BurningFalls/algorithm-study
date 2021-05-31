#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001][2];
int dp[100001][6] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i][0] >> arr[i][1];
	}
	dp[1][arr[1][0]] = 1;
	dp[1][arr[1][1]] = 1;
	FOR(i, 2, N) {
		FOR(j, 1, 5) {
			if (j == arr[i][0] || j == arr[i][1])
				dp[i][j] = dp[i - 1][j] + 1;
			else
				dp[i][j] = 0;
		}
	}
	int maxi = 0;
	int grade = 6;
	FOR(i, 1, N) {
		FOR(j, 1, 5) {
			if (maxi < dp[i][j]) {
				maxi = dp[i][j];
				grade = j;
			}
			else if (maxi == dp[i][j]) {
				grade = min(grade, j);
			}
		}
	}
	cout << maxi << " " << grade;

	return 0;
}