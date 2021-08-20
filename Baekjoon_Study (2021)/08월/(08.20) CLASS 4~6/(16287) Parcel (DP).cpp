#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int W, N;
int arr[5001];
bool dp[400001] = { 0, };

bool Func() {
	FOR(i, 2, N - 2) {
		FOR(j, 1, i - 1) {
			dp[arr[i] + arr[j]] = 1;
		}
		FOR(j, i + 2, N) {
			int t = W - arr[i + 1] - arr[j];
			if (t < 0)
				break;
			if (t <= 400000 && dp[t]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	FASTIO;
	cin >> W >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	cout << (Func() ? "YES" : "NO");


	return 0;
}