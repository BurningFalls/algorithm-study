#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int K, D, A;
	char x;
	cin >> K >> x >> D >> x >> A;
	if (K + A < D || D == 0)
		cout << "hasu";
	else
		cout << "gosu";


	return 0;
}