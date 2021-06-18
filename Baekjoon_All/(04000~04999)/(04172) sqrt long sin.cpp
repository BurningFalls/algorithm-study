#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(double i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000

int X[1000001];

int main() {
	FASTIO;
	X[0] = 1;
	FOR(i, 1, 1000000) {
		int tmp1 = floor(i - sqrt(i));
		int tmp2 = floor(log(i));
		int tmp3 = floor(i * sin(i) * sin(i));
		X[int(i)] = (X[tmp1] + X[tmp2] + X[tmp3]) % MOD;
	}
	while (true) {
		int num;
		cin >> num;
		if (num == -1)
			break;
		cout << X[num] << "\n";
	}


	return 0;
}