#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M;
int num[2001];
bool dp[2001][2001];

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> num[i];
	FOR(dif, 0, N - 1) {
		FOR(start, 1, N - dif) {
			int end = start + dif;
			if (dif == 0)
				dp[start][end] = 1;
			else if (dif == 1)
				dp[start][end] = (num[start] == num[end]);
			else
				dp[start][end] = ((dp[start + 1][end - 1] && (num[start] == num[end])));
		}
	}
	cin >> M;
	FOR(i, 1, M) {
		int S, E;
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}

	return 0;
}