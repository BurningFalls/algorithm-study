#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	M -= N;
	int left = M + N - 1;
	int right = M;
	if (left / 2 < right)
		right = left - right;
	ll up = 1, down = 1;
	ROF(i, left, left - right + 1)
		up *= i;
	FOR(i, 1, right)
		down *= i;
	cout << up / down;


	return 0;
}