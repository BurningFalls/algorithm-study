#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	ll R, C, N;
	cin >> R >> C >> N;
	cout << ((R - 1) / N + 1) * ((C - 1) / N + 1);

	return 0;
}