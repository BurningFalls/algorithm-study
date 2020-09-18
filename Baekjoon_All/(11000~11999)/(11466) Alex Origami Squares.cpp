#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	double a, b;
	cin >> a >> b;
	cout << fixed << setprecision(4);
	if (max(a, b) / 3 <= min(a, b) / 2)
		cout << min(a, b) / 2;
	else {
		if (max(a, b) / 3 <= min(a, b))
			cout << max(a, b) / 3;
		else
			cout << min(a, b);
	}

	return 0;
}