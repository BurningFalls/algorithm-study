#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double B, N;
	while (true) {
		cin >> B >> N;
		if (B == 0 && N == 0)
			break;
		int A = pow(B, 1 / N);
		ll x = pow(A, N);
		ll y = pow(A + 1, N);
		if (B - x >= y - B)
			cout << A + 1;
		else
			cout << A;
		cout << "\n";
	}

	return 0;
}