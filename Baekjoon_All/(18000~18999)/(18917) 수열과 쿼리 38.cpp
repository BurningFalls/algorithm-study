#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll sum = 0;
	ll Xor = 0;
	int M;
	cin >> M;
	FOR(i, 1, M) {
		int kind;
		ll num;
		cin >> kind;
		if (kind == 1) {
			cin >> num;
			sum += num;
			Xor ^= num;
		}
		else if (kind == 2) {
			cin >> num;
			sum -= num;
			Xor ^= num;
		}
		else if (kind == 3) {
			cout << sum << "\n";
		}
		else if (kind == 4) {
			cout << Xor << "\n";
		}
	}


	return 0;
}