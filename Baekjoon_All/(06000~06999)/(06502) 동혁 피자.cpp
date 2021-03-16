#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int idx = 1;
	while (true) {
		int r, w, l;
		cin >> r;
		if (r == 0)
			break;
		cin >> w >> l;
		cout << "Pizza " << idx << " ";
		bool flag = (w * w + l * l <= 4 * r * r);
		if (flag)
			cout << "fits on the table.\n";
		else
			cout << "does not fit on the table.\n";
		idx++;
	}

	return 0;
}