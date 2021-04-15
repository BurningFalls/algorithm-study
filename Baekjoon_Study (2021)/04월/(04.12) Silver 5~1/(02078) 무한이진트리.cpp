#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int A, B;
	cin >> A >> B;
	int left = 0, right = 0;
	while (A != 0 && B != 0) {
		if (A > B) {
			int tmp = A / B;
			A -= tmp * B;
			left += tmp;
		}
		else if (A < B) {
			int tmp = B / A;
			B -= tmp * A;
			right += tmp;
		}
	}
	if (A == 0)
		left--;
	if (B == 0)
		right--;
	cout << left << " " << right;

	return 0;
}