#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	long long int x = 1, y = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		x = (x * i) % MOD;
	for (int i = 1; i <= n - 1; i++) {
		y = (y * 2) % MOD;
	}
	if (x - y < 0)
		cout << x - y + MOD;
	else
		cout << x - y;

	return 0;
}