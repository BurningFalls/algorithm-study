#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<i0nt, int>

int main() {
	FASTIO;
	int B, W;
	cin >> B >> W;
	if (B == 0 && W == 0) {
		cout << "Impossible";
		return 0;
	}
	int tmp = int(sqrt(min(B, W) * 2 + 1));
	if (tmp * tmp > B + W)
		tmp -= 1;
	cout << tmp;


	return 0;
}