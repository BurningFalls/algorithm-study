#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool dp[2000003] = { 0, };

int main() {
	FASTIO;
	int N;
	vector<int> v;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	dp[0] = 1;
	FOR(i, 0, N - 1) {
		sum += v[i];
		for (int j = sum; j - v[i] >= 0; j--) {
			if (dp[j - v[i]] == 0) continue;
			dp[j] = 1;
		}
	}
	FOR(i, 1, sum + 1) {
		if (dp[i] == 0) {
			cout << i;
			break;
		}
	}

	return 0;
}