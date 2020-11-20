#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll S;
	ll idx = 1;
	ll sum = 0;
	cin >> S;
	while (sum + idx <= S) {
		sum += idx;
		idx++;
	}
	cout << idx - 1;

	return 0;
}