#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int t1, t2;
	cin >> t1 >> t2;
	int cnt = 2;
	while (t1 >= t2) {
		int temp = t1 - t2;
		t1 = t2;
		t2 = temp;
		cnt++;
	}
	cout << cnt;

	return 0;
}