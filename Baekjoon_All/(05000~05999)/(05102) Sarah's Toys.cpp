#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		int tmp = a - b;
		if (tmp % 2 == 0) {
			cout << tmp / 2 << " 0\n";
		}
		else if (tmp % 2 == 1) {
			int t = max(tmp - 3, 0);
			cout << t / 2 << " " << (tmp >= 3) << "\n";
		}
	}

	return 0;
}