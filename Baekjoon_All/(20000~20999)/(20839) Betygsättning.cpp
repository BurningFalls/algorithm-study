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
	int x2, y2, z2;
	cin >> x >> y >> z;
	cin >> x2 >> y2 >> z2;
	if (x <= x2 && y <= y2 && z <= z2)
		cout << "A";
	else if (x <= x2 * 2 && y <= y2 && z <= z2)
		cout << "B";
	else if (y <= y2 && z <= z2)
		cout << "C";
	else if (y <= y2 * 2 && z <= z2)
		cout << "D";
	else if (z <= z2)
		cout << "E";

	return 0;
}