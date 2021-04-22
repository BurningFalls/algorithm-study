#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	double left = 0, right = N;
	double R1, R2, B1, B2, Y1, Y2;
	cin >> R1 >> R2;
	cin >> B1 >> B2;
	cin >> Y1 >> Y2;
	double mid = (R1 + R2) / 2;
	left = mid - left, right = right - mid;
	right = mid + max(left, right), left = mid;
	if (B1 < mid)
		B1 = mid * 2 - B1;
	if (B2 < mid)
		B2 = mid * 2 - B2;
	if (Y1 < mid)
		Y1 = mid * 2 - Y1;
	if (Y2 < mid)
		Y2 = mid * 2 - Y2;
	if (B1 != B2) {
		mid = (B1 + B2) / 2;
		left = mid - left, right = right - mid;
		right = mid + max(left, right), left = mid;
		if (Y1 < mid)
			Y1 = mid * 2 - Y1;
		if (Y2 < mid)
			Y2 = mid * 2 - Y2;
	}
	if (Y1 != Y2) {
		mid = (Y1 + Y2) / 2;
		left = mid - left, right = right - mid;
		right = mid + max(left, right), left = mid;
	}
	cout << fixed << setprecision(1);
	cout << right - left;

	return 0;
}