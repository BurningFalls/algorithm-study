#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	ll num = 1;
	FOR(i, 1, N) {
		num *= i;
		while (num % 10 == 0)
			num /= 10;
		num = num % 1000000;
	}
	cout << num % 10;


	return 0;
}