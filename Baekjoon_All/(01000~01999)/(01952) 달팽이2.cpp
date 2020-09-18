#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int M, N;
	cin >> M >> N;
	if (M <= N)
		cout << 2 * M - 2;
	else if (M > N)
		cout << N * 2 - 1;

	return 0;
}