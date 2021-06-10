#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int A, P;
	cin >> A >> P;
	A *= 7;
	P *= 13;
	if (A > P)
		cout << "Axel";
	else if (A < P)
		cout << "Petra";
	else if (A == P)
		cout << "lika";


	return 0;
}