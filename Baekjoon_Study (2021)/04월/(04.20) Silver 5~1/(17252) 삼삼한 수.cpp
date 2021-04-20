#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll N;
	cin >> N;
	if (N == 0) {
		cout << "NO";
		return 0;
	}
	ll num = 1;
	while (num * 3 <= N)
		num *= 3;
	bool flag = true;
	while (num != 0 && N) {
		while (N < num)
			num /= 3;
		N -= num;
		num /= 3;
	}
	cout << ((N == 0) ? "YES" : "NO");

	return 0;
}