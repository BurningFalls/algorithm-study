#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	if (M >= K)
		cout << ((K - 1) + (M / K)) * N;
	else
		cout << M * N;

	return 0;
}