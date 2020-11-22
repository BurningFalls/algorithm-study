#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int func2(ll x) {
	int sum = 0;
	for (ll i = 2; i <= x; i *= 2) {
		sum += x / i;
	}
	return sum;
}

int func5(ll x) {
	int sum = 0;
	for (ll i = 5; i <= x; i *= 5) {
		sum += x / i;
	}
	return sum;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	if (M == 0 && N == M)
		cout << 0;
	else {
		int n_two_cnt = func2(N);
		int n_five_cnt = func5(N);
		int m_two_cnt = func2(M);
		int m_five_cnt = func5(M);
		int nm_two_cnt = func2(N - M);
		int nm_five_cnt = func5(N - M);
		int two_cnt = 0, five_cnt = 0;
		two_cnt = n_two_cnt - (m_two_cnt + nm_two_cnt);
		five_cnt = n_five_cnt - (m_five_cnt + nm_five_cnt);
		cout << min(two_cnt, five_cnt);
	}

	return 0;
}