#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[5001];
int dp1[5001];
int dp2[5001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	dp1[1] = 1;
	FOR(i, 2, N) {
		if (arr[i - 1] < arr[i])
			dp1[i] = dp1[i - 1] + 1;
		else
			dp1[i] = 1;
	}
	dp2[N] = 1;
	ROF(i, N - 1, 1) {
		if (arr[i] > arr[i + 1])
			dp2[i] = dp2[i + 1] + 1;
		else
			dp2[i] = 1;
	}
	int maxi = 0;
	FOR(i, 1, N) {
		maxi = max(maxi, dp1[i] + dp2[i] - 1);
	}
	cout << maxi;

	return 0;
}