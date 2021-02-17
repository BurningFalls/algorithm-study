#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int arr[7][2] = { 0, };

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N) {
		int S, Y;
		cin >> S >> Y;
		arr[Y][S] += 1;
	}
	int ans = 0;
	int temp = arr[1][0] + arr[1][1] + arr[2][0] + arr[2][1];
	ans += temp / K;
	if (temp % K != 0)
		ans += 1;
	temp = arr[3][0] + arr[4][0];
	ans += temp / K;
	if (temp % K != 0)
		ans += 1;
	temp = arr[5][0] + arr[6][0];
	ans += temp / K;
	if (temp % K != 0)
		ans += 1;
	temp = arr[3][1] + arr[4][1];
	ans += temp / K;
	if (temp % K != 0)
		ans += 1;
	temp = arr[5][1] + arr[6][1];
	ans += temp / K;
	if (temp % K != 0)
		ans += 1;

	cout << ans;

	return 0;
}