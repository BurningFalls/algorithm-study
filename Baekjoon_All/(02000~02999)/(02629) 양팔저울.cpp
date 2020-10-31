#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int arr[31];
int ball[8];
bool dp[31][15001] = { 0, };

void DP(int cnt, int weight) {
	if (cnt > N)
		return;
	if (dp[cnt][weight])
		return;
	dp[cnt][weight] = 1;
	DP(cnt + 1, weight);
	DP(cnt + 1, weight + arr[cnt]);
	DP(cnt + 1, abs(weight - arr[cnt]));
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1)
		cin >> arr[i];

	DP(0, 0);

	cin >> M;
	FOR(i, 1, M)
		cin >> ball[i];

	FOR(i, 1, M) {
		if (ball[i] > 15000)
			cout << "N ";
		else {
			if (dp[N][ball[i]])
				cout << "Y ";
			else
				cout << "N ";
		}
	}

	return 0;
}