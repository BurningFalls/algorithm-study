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
	cin >> T;
	while (T--) {
		int C, D;
		cin >> C >> D;
		if (C == 0 && D == 0)
			cout << 0;
		else if (C == D)
			cout << 1;
		else if (abs(C - D) % 2 == 1)
			cout << -1;
		else if (abs(C - D) % 2 == 0)
			cout << 2;
		cout << "\n";
	}

	return 0;
}