#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int Func(int x) {
	int cnt = 0;
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			cnt += 1;
			x /= i;
		}
	}
	if (x != 1)
		cnt++;
	return cnt;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int a, b, k;
		cin >> a >> b >> k;
		int mini = ((a != b && (a % b == 0 || b % a == 0)) ? 1 : 2);
		int maxi = Func(a) + Func(b);
		cout << ((mini <= k && k <= maxi) ? "Yes" : "No") << "\n";
	}

	return 0;
}