#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int a, d, k;
	cin >> a >> d >> k;
	if ((k - a) % d != 0 || (k - a) / d + 1 <= 0)
		cout << 'X';
	else
		cout << (k - a) / d + 1;

	return 0;
}