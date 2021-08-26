#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
string arr[16];
ll dp[(1 << 15)][100] = { 0, };
int ten_mod[51];
int arr_mod[51];

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

void Calc_ten_mod() {
	ten_mod[0] = 1 % K;
	FOR(i, 1, 50)
		ten_mod[i] = (ten_mod[i - 1] * 10) % K;
}

void Calc_arr_mod() {
	FOR(i, 0, N - 1) {
		string s = arr[i];
		int len = s.size();
		int tmp = 0;
		FOR(j, 0, len - 1) {
			tmp *= 10;
			tmp += s[j] - '0';
			tmp %= K;
		}
		arr_mod[i] = tmp;
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1)
		cin >> arr[i];
	cin >> K;
	Calc_ten_mod();
	Calc_arr_mod();
	dp[0][0] = 1;
	FOR(cur, 1, (1 << N) - 1) {
		FOR(i, 0, N - 1) {
			if (!(cur & (1 << i))) continue;
			int prev = cur & ~(1 << i);
			FOR(prevK, 0, K - 1) {
				int curK = ((prevK * ten_mod[arr[i].size()]) % K + arr_mod[i]) % K;
				dp[cur][curK] += dp[prev][prevK];
			}
		}
	}
	ll up = dp[(1 << N) - 1][0];
	ll down = 1;
	FOR(i, 1, N)
		down = down * i;
	ll gcd = GCD(up, down);
	up /= gcd;
	down /= gcd;
	cout << up << "/" << down;


	return 0;
}