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
	int idx = 1;
	while (T--) {
		double A, B;
		cin >> A >> B;
		int x = ceil(pow(A, 1.0 / 3.0));
		int y = floor(pow(B, 1.0 / 3.0));
		cout << "Case #" << idx << ": " << y - x + 1 << "\n";
		idx++;
	}

	return 0;
}