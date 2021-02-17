#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	int K;
	cin >> K;
	FOR(i, 1, K)
		cout << 1;
	FOR(i, 1, K - 1)
		cout << 0;

	return 0;
}