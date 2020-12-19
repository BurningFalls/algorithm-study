#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define act 100000000

int main() {
	FASTIO;
	int C;
	cin >> C;
	while (C--) {
		string s;
		ll N, T, L;
		bool flag = false;
		cin >> s >> N >> T >> L;
		if (s == "O(N)") {
			if (N * T <= L * act)
				flag = true;
			else
				flag = false;
		}
		else if (s == "O(N^2)") {
			if (N * N * T <= L * act)
				flag = true;
			else
				flag = false;
		}
		else if (s == "O(N^3)") {
			ll temp = 1;
			flag = true;
			FOR(i, 1, N) {
				temp = (ll)i * i * i;
				if (temp * T > L* act) {
					flag = false;
					break;
				}
			}
		}
		else if (s == "O(2^N)") {
			ll temp = 1;
			flag = true;
			FOR(i, 1, N) {
				temp *= 2;
				if (temp * T > L* act) {
					flag = false;
					break;
				}
			}
		}
		else if (s == "O(N!)") {
			ll temp = 1;
			flag = true;
			FOR(i, 1, N) {
				temp *= i;
				if (temp * T > L * act) {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			cout << "May Pass.";
		else
			cout << "TLE!";
		cout << "\n";
	}

	return 0;
}