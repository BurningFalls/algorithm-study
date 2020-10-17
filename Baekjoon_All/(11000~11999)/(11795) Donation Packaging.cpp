#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	int A = 0, B = 0, C = 0;
	FOR(i, 1, T) {
		int a, b, c;
		cin >> a >> b >> c;
		A += a;
		B += b;
		C += c;
		int minimum = min({ A, B, C });
		if (minimum >= 30) {
			cout << minimum;
			A -= minimum;
			B -= minimum;
			C -= minimum;
		}
		else
			cout << "NO";
		cout << "\n";
	}

	return 0;
}