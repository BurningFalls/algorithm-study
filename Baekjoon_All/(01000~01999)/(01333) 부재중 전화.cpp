#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

bool Song[1100000] = { 0, };
bool Bell[1100000] = { 0, };

int main() {
	FASTIO;
	int N, L, D;
	cin >> N >> L >> D;
	int temp = N * L + 5 * (N - 1);
	for (int i = 0; i < temp; i++) {
		int x = i % (L + 5);
		if (0 <= x && x <= L - 1)
			Song[i] = 1;
	}
	for (int i = 0; i <= temp + D - 1; i++) {
		int x = i % D;
		if (x == 0)
			Bell[i] = 1;
	}
	FOR(i, 0, temp + D - 1) {
		if (Song[i] == 0 && Bell[i] == 1) {
			cout << i;
			break;
		}
	}

	return 0;
}