#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double x, y;
	cout << fixed << setprecision(2);
	while (true) {
		cin >> x;
		if (x < 0)
			break;
		y = x * 0.167;
		cout << "Objects weighing ";
		cout << x;
		cout << " on Earth will weigh ";
		cout << y;
		cout << " on the moon.\n";
	}

	return 0;
}