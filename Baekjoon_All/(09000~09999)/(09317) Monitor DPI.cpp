#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	double D, H, V;
	cout << fixed << setprecision(2);
	while (true) {
		cin >> D >> H >> V;
		if (D == 0 && H == 0 && V == 0)
			break;
		cout << "Horizontal DPI: ";
		double W = (16 * D / sqrt(337));
		cout << H / W;
		cout << "\n";
		cout << "Vertical DPI: ";
		cout << V / (9 * W / 16);
		cout << "\n";
	}

	return 0;
}