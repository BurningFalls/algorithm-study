#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	int idx = 1;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << "Case " << idx << ": ";
		if (a / b == 0 && a % b == 0)
			cout << "0";
		else {
			if (a / b != 0)
				cout << a / b << " ";
			if (a % b != 0)
				cout << a % b << "/" << b;
		}
		cout << "\n";
		idx++;
	}

	return 0;
}