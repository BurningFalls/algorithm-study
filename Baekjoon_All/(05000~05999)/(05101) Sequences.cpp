#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		if (a > c)
			cout << "X";
		else {
			if ((c - a) % b == 0)
				cout << 1 + (c - a) / b;
			else
				cout << "X";
		}
		cout << "\n";
	}


	return 0;
}