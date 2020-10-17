#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int s, v1, v2;
int ans1 = -1, ans2 = -1;
int sum = -1;

bool func() {
	for (int i = 0; v1 * i <= s; i++) {
		int temp = s - v1 * i;
		if (temp % v2 == 0) {
			int a = i;
			int b = temp / v2;
			if (sum == -1) {
				sum = a + b;
				ans1 = a;
				ans2 = b;
			}
			else {
				if (sum > a + b) {
					sum = a + b;
					ans1 = a;
					ans2 = b;
				}
			}
		}
	}
	if (ans1 == -1 && ans2 == -1)
		return false;
	return true;
}

int main() {
	FASTIO;
	cin >> s >> v1 >> v2;
	if (func())
		cout << ans1 << " " << ans2;
	else
		cout << "Impossible";

	return 0;
}