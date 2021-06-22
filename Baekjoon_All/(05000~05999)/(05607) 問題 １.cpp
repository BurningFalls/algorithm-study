#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	int sumA = 0, sumB = 0;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			sumA += (a + b);
		else if (a < b)
			sumB += (a + b);
		else if (a == b) {
			sumA += a;
			sumB += b;
		}
	}
	cout << sumA << " " << sumB;


	return 0;
}