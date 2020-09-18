#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int n;
	cin >> n;
	int num;
	int zero_cnt = 0;
	int one_cnt = 0;
	FOR(i, 1, n) {
		cin >> num;
		if (num == 0)
			zero_cnt++;
		else if (num == 1)
			one_cnt++;
	}
	cout << n - max(zero_cnt, one_cnt);

	return 0;
}