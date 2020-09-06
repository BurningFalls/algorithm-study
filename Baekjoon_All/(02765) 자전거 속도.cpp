#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define PI 3.1415927
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	cout << fixed << setprecision(2);
	int idx = 1;
	while (true) {
		double a, b, c;
		cin >> a >> b >> c;
		if (b == 0)
			break;
		double temp = PI * a * b / 63360;
		cout << "Trip #" << idx << ": ";
		cout << temp << " ";
		cout << temp * 3600 / c << "\n";
		idx++;
	}

	return 0;
}