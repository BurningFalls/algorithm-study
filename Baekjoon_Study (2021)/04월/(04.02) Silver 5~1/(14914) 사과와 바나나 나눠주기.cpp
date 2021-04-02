#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, b;
	cin >> a >> b;
	FOR(i, 1, min(a, b)) {
		if (a % i == 0 && b % i == 0) {
			cout << i << " " << a / i << " " << b / i << "\n";
		}
	}


	return 0;
}