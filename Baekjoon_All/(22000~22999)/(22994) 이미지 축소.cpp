#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[1001][1001];

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int ni, mj;
	cin >> ni >> mj;
	FOR(i, 1, ni) {
		FOR(j, 1, mj) {
			cin >> arr[i][j];
		}
	}

	int Hm = 0;
	FOR(i, 1, ni) {
		int cnt = 1;
		char prev = arr[i][1];
		int gcd = -1;
		bool flag = false;
		FOR(j, 2, mj) {
			if (prev != arr[i][j]) {
				if (!flag) {
					flag = true;
					gcd = cnt;
				}
				else
					gcd = GCD(gcd, cnt);
				cnt = 1;
			}
			else
				cnt++;
			prev = arr[i][j];
		}
		if (!flag)
			gcd = cnt;
		else
			gcd = GCD(gcd, cnt);
		if (i == 1)
			Hm = gcd;
		else {
			if (max(Hm, gcd) % min(Hm, gcd) == 0)
				Hm = min(Hm, gcd);
			else
				Hm = 1;
		}
	}

	int Vm = 0;
	FOR(i, 1, mj) {
		int cnt = 1;
		char prev = arr[1][i];
		int gcd = -1;
		bool flag = false;
		FOR(j, 2, ni) {
			if (prev != arr[j][i]) {
				if (!flag) {
					flag = true;
					gcd = cnt;
				}
				else
					gcd = GCD(gcd, cnt);
				cnt = 1;
			}
			else
				cnt++;
			prev = arr[j][i];
		}
		if (!flag)
			gcd = cnt;
		else
			gcd = GCD(gcd, cnt);
		if (i == 1)
			Vm = gcd;
		else {
			if (max(Vm, gcd) % min(Vm, gcd) == 0)
				Vm = min(Vm, gcd);
			else
				Vm = 1;
		}
	}
	cout << ni / Vm << " " << mj / Hm << "\n";
	for (int i = 1; i <= ni; i += Vm) {
		for (int j = 1; j <= mj; j += Hm)
			cout << arr[i][j];
		cout << "\n";
	}

	return 0;
}