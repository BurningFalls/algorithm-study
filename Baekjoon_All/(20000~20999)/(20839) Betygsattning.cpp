#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int x, y, z;
	int a, b, c;
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	int hx = (x - 1) / 2 + 1;
	int hy = (y - 1) / 2 + 1;
	int hz = (z - 1) / 2 + 1;
	if (a >= x && b >= y && c >= z)
		cout << 'A';
	else if (a >= hx && b >= hy && c >= hz)
		cout << 'B';
	else if (b >= y && c >= z)
		cout << 'C';
	else if (b >= hy && c >= hz)
		cout << 'D';
	else
		cout << 'E';


	return 0;
}