#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> prime_v;
int len;

bool Prime_Check(int x) {
	if (x == 2)
		return true;
	FOR(i, 2, sqrt(x)) {
		if (x % i == 0)
			return false;
	}
	return true;
}

bool func(int num) {
	FOR(i, 0, len - 1) {
		int a = prime_v[i];
		FOR(j, i, len - 1) {
			int b = prime_v[j];
			FOR(k, j, len - 1) {
				int c = prime_v[k];
				if (a + b + c == num) {
					cout << a << " " << b << " " << c;
					return 1;
				}
				else if (a + b + c > num)
					break;
			}
			if (a + b > num)
				break;
		}
		if (a > num)
			break;
	}
	return 0;
}

int main() {
	FASTIO;
	FOR(i, 2, 999) {
		if (Prime_Check(i))
			prime_v.push_back(i);
	}
	len = prime_v.size();
	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> K;
		if (!func(K))
			cout << 0;
		cout << "\n";
	}

	return 0;
}