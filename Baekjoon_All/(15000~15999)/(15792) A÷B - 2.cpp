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
	cout << A / B << ".";
	A = A % B;
	FOR(i, 0, 1000) {
		A *= 10;
		cout << A / B;
		A = A - (A / B) * B;
	}

	return 0;
}