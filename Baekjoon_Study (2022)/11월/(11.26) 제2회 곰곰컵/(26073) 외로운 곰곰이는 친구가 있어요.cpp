#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 0, N - 1) {
		int X, Y, K;
		cin >> X >> Y;
		cin >> K;
		X = abs(X); Y = abs(Y);
		int gcd = -1;
		FOR(j, 0, K - 1) {
			int num;
			cin >> num;
			if (gcd == -1) {
				gcd = num;
			}
			else {
				gcd = GCD(gcd, num);
			}
		}

		cout << ((X % gcd == 0 && Y % gcd == 0) ? "Ta-da" : "Gave up") << "\n";
	}


	return 0;
}