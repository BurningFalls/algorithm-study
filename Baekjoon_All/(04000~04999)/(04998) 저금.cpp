#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	double N, B, M;
	while (cin >> N >> B >> M) {
		int year = 0;
		while (N <= M) {
			year++;
			N = N + N * (B / 100);
		}
		cout << year << "\n";
	}


	return 0;
}