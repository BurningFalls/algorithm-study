#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool dp[200001] = { 0, };
vector<int> v[100001];

int main() {
	FASTIO;
	int K;
	cin >> K;
	FOR(i, 1, K) {
		for (int j = i; j <= K; j += i) {
			v[j].push_back(i);
		}
	}
	dp[K] = 1;
	ROF(i, K - 1, 1) {
		for (int n : v[i])
			dp[i] |= dp[i + n];
		dp[i] = !dp[i];
	}
	cout << (dp[1] ? "Ringo" : "Kali");

	return 0;
}