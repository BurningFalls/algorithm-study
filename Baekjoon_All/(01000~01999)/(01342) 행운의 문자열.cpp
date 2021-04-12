#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool Check(string s) {
	int len = s.size();
	FOR(i, 0, len - 2) {
		if (s[i] == s[i + 1])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	string S;
	int cnt = 0;
	int len;
	cin >> S;
	len = S.size();
	sort(S.begin(), S.end());
	bool flag = true;
	while (flag) {
		if (Check(S))
			cnt++;
		flag = next_permutation(S.begin(), S.end());
	}
	cout << cnt;

	return 0;
}