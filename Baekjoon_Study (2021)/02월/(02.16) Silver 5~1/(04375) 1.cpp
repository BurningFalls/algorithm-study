#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int n;
	while (cin >> n) {
		int num = 0;
		FOR(i, 1, n) {
			num = num * 10 + 1;
			num %= n;
			if (num == 0) {
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}