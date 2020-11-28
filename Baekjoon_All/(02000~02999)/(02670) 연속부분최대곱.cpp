#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

double arr[10001];
double dp[10001];

int main() {
	FASTIO;
	int N;
	double maximum = 0;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	dp[0] = 1;
	FOR(i, 1, N) {
		dp[i] = max(arr[i], dp[i - 1] * arr[i]);
		maximum = max(maximum, dp[i]);
	}
	cout << fixed << setprecision(3);
	cout << maximum;

	return 0;
}