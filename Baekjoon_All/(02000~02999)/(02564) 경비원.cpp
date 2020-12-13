#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pii arr[102];

int main() {
	FASTIO;
	int M, N;
	int K;
	int A, B;
	cin >> M >> N;
	cin >> K;
	FOR(i, 1, K + 1) {
		int a, b;
		cin >> a >> b;
		if (a == 1)
			arr[i] = { 0, b };
		else if (a == 2)
			arr[i] = { N, b };
		else if (a == 3)
			arr[i] = { b, 0 };
		else if (a == 4)
			arr[i] = { b, M };
	}
	int Y = arr[K + 1].first;
	int X = arr[K + 1].second;
	int ans = 0;
	FOR(i, 1, K) {
		if (arr[i].first == 0) {
			if (Y == 0)
				ans += abs(arr[i].second - X);
			else if (Y == N)
				ans += N + min(arr[i].second + X, (M - arr[i].second) + (M - X));
			else if (X == 0)
				ans += arr[i].second + Y;
			else if (X == M)
				ans += (M - arr[i].second) + Y;
		}
		else if (arr[i].first == N) {
			if (Y == 0)
				ans += N + min(arr[i].second + X, (M - arr[i].second) + (M - X));
			else if (Y == N)
				ans += abs(arr[i].second - X);
			else if (X == 0)
				ans += arr[i].second + (N - Y);
			else if (X == M)
				ans += (M - arr[i].second) + (N - Y);
		}
		else if (arr[i].second == 0) {
			if (Y == 0)
				ans += arr[i].first + X;
			else if (Y == N)
				ans += (N - arr[i].first) + X;
			else if (X == 0)
				ans += abs(arr[i].first - Y);
			else if (X == M)
				ans += M + min(arr[i].first + Y, (N - arr[i].first) + (N - Y));
		}
		else if (arr[i].second == M) {
			if (Y == 0)
				ans += arr[i].first + (M - X);
			else if (Y == N)
				ans += (N - arr[i].first) + (M - X);
			else if (X == 0)
				ans += M + min(arr[i].first + Y, (N - arr[i].first) + (N - Y));
			else if (X == M)
				ans += abs(arr[i].first - Y);
		}
	}
	cout << ans;

	return 0;
}