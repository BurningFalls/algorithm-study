#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double a, b, c, d;
	while (true) {
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;
		int min1 = min(c / a * 100, d / b * 100);
		int min2 = min(c / b * 100, d / a * 100);
		int temp = max(min1, min2);
		if (temp > 100)
			cout << 100;
		else
			cout << temp;
		cout << "%\n";
	}

	return 0;
}