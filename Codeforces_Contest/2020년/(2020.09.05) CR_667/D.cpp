#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		ll x;
		string n;
		int s;
		int sum = 0;
		int pos = -2;
		cin >> x >> s;
		n = to_string(x);
		bool flag = false;
		FOR(i, 0, n.size() - 1) {
			sum += (n[i] - '0');
			if (flag == false && sum >= s) {
				flag = true;
				pos = i - 1;
			}
		}
		if (s >= sum)
			cout << 0;
		else if (pos == -1) {
			cout << ll(pow(10, n.size())) - x;
		}
		else {
			string temp = "";
			FOR(i, 0, pos - 1) {
				temp += n[i];
			}
			temp += (n[pos] + 1);
			FOR(i, pos + 1, n.size() - 1) {
				temp += '0';
			}
			ll ans = 0;
			FOR(i, 0, temp.size() - 1) {
				ans += (temp[i] - '0') * ll(pow(10, temp.size() - 1 - i));
			}
			cout << ans - x;
		}
		cout << "\n";
	}

	return 0;
}