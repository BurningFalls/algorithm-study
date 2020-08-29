#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int num;
	int cnt[3] = { 0, };
	FOR(i, 1, 3) {
		cin >> num;
		cnt[num]++;
	}
	if (cnt[1] > cnt[2])
		cout << 1;
	else if (cnt[1] < cnt[2])
		cout << 2;

	return 0;
}