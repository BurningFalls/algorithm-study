#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(ll i=(a);i>=(b);i--)
#define pii pair<int, int>

bool not_Prime[1000001] = { 0, };

void Find_Prime() {
	for (int j = 2; 2 * j <= 1000000; j++) {
		not_Prime[2 * j] = 1;
	}
	for (int i = 3; i <= 1000000; i += 2) {
		if (not_Prime[i]) continue;
		for (int j = 2; i * j <= 1000000; j++) {
			not_Prime[i * j] = 1;
		}
	}
}

int main() {
	FASTIO;
	int N;
	not_Prime[1] = 1;
	Find_Prime();
	cin >> N;
	FOR(i, 1, N) {
		ll num;
		cin >> num;
		ll tmp = sqrt(num);
		bool flag = false;
		FOR(j, 2, min(tmp, 1000000LL)) {
			if (not_Prime[j]) continue;
			if (num % j == 0) {
				flag = true;
				break;
			}
		}
		cout << (flag ? "NO" : "YES") << "\n";
	}

	return 0;
}