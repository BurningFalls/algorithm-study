#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	ll N, b;
	cin >> N >> b;
	if (pow(2, b + 1) - 1 >= N)
		cout << "yes";
	else
		cout << "no";

	return 0;
}