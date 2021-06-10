#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int t1, v1, t2, v2;
	cin >> t1 >> v1 >> t2 >> v2;
	if (t2 < 0 && v2 >= 10)
		cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
	else if (t2 < t1)
		cout << "MCHS warns! Low temperature is expected tomorrow.";
	else if (v1 < v2)
		cout << "MCHS warns! Strong wind is expected tomorrow.";
	else
		cout << "No message";

	return 0;
}