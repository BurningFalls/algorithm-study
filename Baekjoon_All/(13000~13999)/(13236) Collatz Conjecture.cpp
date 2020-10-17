#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int n;
	cin >> n;
	while (n != 1) {
		cout << n << " ";
		if (n % 2 == 0)
			n /= 2;
		else if (n % 2 == 1)
			n = n * 3 + 1;
	}
	cout << 1;

	return 0;
}