#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool is_Prime(int x) {
	if (x == 1)
		return false;
	if (x == 2)
		return true;
	int tmp = sqrt(x);
	FOR(i, 2, tmp) {
		if (x % i == 0)
			return false;
	}
	return true;
}

bool is_Exist(int num, int x) {
	string s = to_string(num);
	int len = s.size();
	FOR(i, 0, len - 1) {
		if ((s[i] - '0') == x)
			return true;
	}
	return false;
}

int main() {
	FASTIO;
	int A, B, D;
	int cnt = 0;
	cin >> A >> B >> D;
	FOR(num, A, B) {
		if (!is_Prime(num)) continue;
		cnt += is_Exist(num, D);
	}
	cout << cnt;

	return 0;
}