#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define PI 3.14159265358979

int main() {
	FASTIO;
	long double N;
	cin >> N;
	cout << fixed << setprecision(6);
	cout << 2 * sqrt(PI * N);

	return 0;
}