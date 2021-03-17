#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

struct REC {
	ll x1, x2, y1, y2;
};

int main() {
	FASTIO;
	ll x1, x2, y1, y2;
	REC R1, R2;
	cin >> x1 >> y1 >> x2 >> y2;
	R1.x1 = x1, R1.x2 = x2, R1.y1 = y1, R1.y2 = y2;
	cin >> x1 >> y1 >> x2 >> y2;
	R2.x1 = x1, R2.x2 = x2, R2.y1 = y1, R2.y2 = y2;

	if (R1.x1 == R2.x2 || R1.x2 == R2.x1) {
		if (R1.y1 == R2.y2 || R1.y2 == R2.y1)
			cout << "POINT";
		else if ((R1.y2 - R1.y1) + (R2.y2 - R2.y1) > max(R2.y2 - R1.y1, R1.y2 - R2.y1))
			cout << "LINE";
		else
			cout << "NULL";
	}
	else if ((R1.x2 - R1.x1) + (R2.x2 - R2.x1) > max(R2.x2 - R1.x1, R1.x2 - R2.x1)) {
		if (R1.y1 == R2.y2 || R1.y2 == R2.y1)
			cout << "LINE";
		else if ((R1.y2 - R1.y1) + (R2.y2 - R2.y1) > max(R2.y2 - R1.y1, R1.y2 - R2.y1))
			cout << "FACE";
		else
			cout << "NULL";
	}
	else
		cout << "NULL";


	return 0;
}