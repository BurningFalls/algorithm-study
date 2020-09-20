#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int n;
	int num;
	int sum = 0;
	cin >> n;
	FOR(i, 1, n) {
		int maximum = 0;
		FOR(j, 1, n) {
			cin >> num;
			maximum = max(maximum, num);
		}
		if (maximum > 0)
			sum += maximum;
	}
	cout << sum;

	return 0;
}