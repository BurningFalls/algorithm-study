#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		ll a, b, c;
		char x, y;
		cin >> a >> x >> b >> y >> c;
		bool flag = false;
		if (x == '+') {
			if (a + b == c)
				flag = true;
		}
		else if (x == '-') {
			if (a - b == c)
				flag = true;
		}
		else if (x == '*') {
			if (a * b == c)
				flag = true;
		}
		else if (x == '/') {
			if (a % b == 0 && a / b == c)
				flag = true;
		}
		if (flag)
			cout << "correct";
		else
			cout << "wrong answer";
		cout << "\n";
	}


	return 0;
}