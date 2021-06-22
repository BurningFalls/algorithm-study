#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[23];
int dp[800000] = { 0, };

int main() {
	FASTIO;
	int C, B;
	cin >> C >> B;
	int sum = 0;
	FOR(i, 1, B) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr + 1, arr + B + 1);
	dp[0] = 1;
	FOR(i, 1, B) {
		ROF(j, sum, arr[i]) {
			if (dp[j - arr[i]])
				dp[j] = 1;
		}
	}
	int idx = C;
	while (!dp[idx]) {
		idx--;
	}
	cout << idx;

	return 0;
}