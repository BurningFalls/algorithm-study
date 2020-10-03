#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll N;
	int score = 0;
	cin >> N;
	while (N != 1) {
		if (N % 2 == 1)
			N = N * 3 + 1;
		else if (N % 2 == 0)
			N /= 2;
		score++;
	}
	cout << score;

	return 0;
}