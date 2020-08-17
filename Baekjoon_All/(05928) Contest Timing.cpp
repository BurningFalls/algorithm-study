#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int D, H, M;
	int sum = 0;
	cin >> D >> H >> M;
	int start = 11 * 1440 + 11 * 60 + 11;
	int end = D * 1440 + H * 60 + M;
	if (end < start) {
		cout << -1;
	}
	else {
		cout << end - start;
	}

	return 0;
}