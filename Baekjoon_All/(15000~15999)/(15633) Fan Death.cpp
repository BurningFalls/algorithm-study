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
	int sum = 0;
	FOR(i, 1, n) {
		if (n % i == 0)
			sum += i;
	}
	cout << sum * 5 - 24;

	return 0;
}