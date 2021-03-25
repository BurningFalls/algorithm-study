#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll STOL(string s) {
	ll result = 0;
	int len = s.size();
	FOR(i, 0, len - 1) {
		result += (s[i] - '0') * pow(10, len - 1 - i);
	}
	return result;
}

int main() {
	FASTIO;
	ll N;
	ll ans = 1;
	cin >> N;
	FOR(i, 1, N) {
		ans *= i;
		string tmp = to_string(ans);
		int len = tmp.size();
		string result = "";
		bool flag = false;
		int cnt = 0;
		ROF(i, len - 1, 0) {
			if (!flag && tmp[i] == '0')
				continue;
			flag = true;
			result += tmp[i];
			cnt++;
			if (cnt == 12)
				break;
		}
		reverse(result.begin(), result.end());
		ans = STOL(result);
	}
	string tmp = to_string(ans);
	int tmp_len = tmp.size();
	FOR(i, tmp_len - 5, tmp_len - 1)
		cout << tmp[i];

	return 0;
}