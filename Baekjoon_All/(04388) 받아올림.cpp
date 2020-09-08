#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	string a, b;
	while (true) {
		int ans = 0;
		cin >> a >> b;
		if (a == "0" && b == "0")
			break;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int len_a = a.size(), len_b = b.size();
		if (len_a >= len_b) {
			FOR(i, 1, len_a - len_b)
				b += "0";
			int flag = 0;
			FOR(i, 0, len_a - 1) {
				int temp = (a[i] - '0') + (b[i] - '0') + flag;
				if (temp >= 10) {
					ans++;
					flag = 1;
				}
				else
					flag = 0;
			}
		}
		else if (len_a < len_b) {
			FOR(i, 1, len_b - len_a)
				a += "0";
			int flag = 0;
			FOR(i, 0, len_b - 1) {
				int temp = a[i] + b[i] + flag;
				if (temp >= 10) {
					ans++;
					flag = 1;
				}
				else
					flag = 0;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}