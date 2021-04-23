#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool is_PD(int x) {
	string s = to_string(x);
	int len = s.size();
	FOR(i, 0, len / 2 - 1) {
		if (s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}

bool is_Prime(int x) {
	if (x == 2)
		return true;
	int tmp = sqrt(x);
	FOR(i, 2, tmp) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int A, B;
	cin >> A >> B;
	FOR(i, A, B) {
		if (i % 2 == 0) continue;
		if (i % 10 == 0) continue;
		if (!is_PD(i)) continue;
		if (!is_Prime(i)) continue;
		cout << i << "\n";
	}
	cout << -1;

	return 0;
}