#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	int b, d;
	b = to_string(B).size();
	d = to_string(D).size();
	cout << ll((A * pow(10, b) + B) + (C * pow(10, d) + D));

	return 0;
}