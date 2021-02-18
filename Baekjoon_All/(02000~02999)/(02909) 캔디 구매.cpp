#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	double C;
	int K;
	int x;
	cin >> C >> K;
	C = C / pow(10, K);
	x = round(C);
	cout << x * int(pow(10, K)) << "\n";

	return 0;
}