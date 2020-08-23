#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int cnt = 0;
int ans = 50001;

void func(int num) {
	if (num == 0) {
		ans = min(ans, cnt);
		return;
	}
	if (cnt >= ans - 1)
		return;
	int temp = sqrt(num);
	while (temp > 0) {
		cnt++;
		func(num - temp * temp);
		cnt--;
		temp--;
	}
}

int main() {
	FASTIO;
	int n;
	cin >> n;
	func(n);
	cout << ans;

	return 0;
}