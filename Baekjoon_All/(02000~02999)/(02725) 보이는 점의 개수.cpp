#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int cnt[1001] = { 0, };

int main() {
	FASTIO;
	int C;
	cin >> C;
	cnt[0] = 0;
	cnt[1] = 3;
	FOR(i, 2, 1000) {
		int temp = 0;
		FOR(j, 2, i - 1) {
			if (GCD(i, j) == 1)
				temp++;
		}
		cnt[i] = cnt[i - 1] + (temp + 1) * 2;
	}
	while (C--) {
		int N;
		cin >> N;
		cout << cnt[N] << "\n";
	}

	return 0;
}