#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

ll Calc(string s, ll t) {
	ll cnt = 0;
	FOR(i, 0, LEN(s) - 2) {
		if (s[i] == '(' && s[i + 1] == ')') {
			cnt++;
		}
	}
	cnt *= t;
	if (s[0] == ')' && s.back() == '(') {
		cnt += (t - 1);
	}
	return cnt;
}

int main() {
	FASTIO;
	ll N, K;
	cin >> N >> K;
	string s1, s2;
	ll len1, len2;
	cin >> s1 >> len1;
	cin >> s2 >> len2;
	ll money = Calc(s1, len1);
	ll earn = Calc(s2, len2);
	if (money < K) {
		cout << 0;
	}
	else if (money >= K) {
		if (earn >= K) {
			cout << N;
		}
		else if (earn < K) {
			cout << min(N, (money - K) / (K - earn) + 1);
		}
	}


	return 0;
}