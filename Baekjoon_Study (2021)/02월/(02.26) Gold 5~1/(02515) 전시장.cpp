#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MAX 300000 + 1

int N, S;
pii picture[MAX];
ll dp[MAX] = { 0, };
ll maximum[MAX];

int UB(int s, int e, int target) {
	while (s < e) {
		int mid = (s + e) / 2;
		if (picture[mid].first <= target)
			s = mid + 1;
		else
			e = mid;
	}
	return e;
}

int main() {
	FASTIO;
	cin >> N >> S;
	FOR(i, 1, N) {
		int h, c;
		cin >> h >> c;
		picture[i] = { h, c };
	}
	sort(picture + 1, picture + N + 1);
	picture[0] = { -1, 0 };
	maximum[0] = 0;
	dp[1] = picture[1].second;
	maximum[1] = dp[1];
	FOR(i, 2, N) {
		int tmp = max(picture[i].first - S, 0);
		int ub = UB(0, i, tmp);
		dp[i] = maximum[ub - 1] + picture[i].second;
		maximum[i] = max(maximum[i - 1], dp[i]);
	}
	cout << maximum[N];

	return 0;
}