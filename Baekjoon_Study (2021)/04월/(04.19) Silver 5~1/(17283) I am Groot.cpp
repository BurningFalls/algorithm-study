#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int L, R;
	int sum = 0;
	cin >> L >> R;
	int cnt = 2;
	L = L * R / 100;
	while (L > 5) {
		sum += L * cnt;
		cnt *= 2;
		L = L * R / 100;
	}
	cout << sum;


	return 0;
}