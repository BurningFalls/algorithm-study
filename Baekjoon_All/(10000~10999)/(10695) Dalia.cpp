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
		int n, r1, c1, r2, c2;
		cin >> n >> r1 >> c1 >> r2 >> c2;
		cout << "Case " << idx << ": ";
		int temp1 = abs(r2 - r1);
		int temp2 = abs(c2 - c1);
		if ((temp1 == 1 && temp2 == 2) || (temp1 == 2 && temp2 == 1))
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
		idx++;
	}

	return 0;
}