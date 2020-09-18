#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double x;
	while (true) {
		cin >> x;
		if (x == 0)
			break;
		double temp = 0;
		double i = 1;
		while(true) {
			temp += 1 / (i + 1);
			if (temp >= x) {
				cout << i;
				break;
			}
			i++;
		}
		cout << " card(s)\n";
	}

	return 0;
}