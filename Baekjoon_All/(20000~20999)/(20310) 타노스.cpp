#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

deque<int> zero, one;

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = s.size();
	int zero_cnt = 0, one_cnt = 0;
	FOR(i, 0, len - 1) {
		if (s[i] == '0') {
			zero.push_back(i);
			zero_cnt++;
		}
		else if (s[i] == '1') {
			one.push_back(i);
			one_cnt++;
		}
	}
	FOR(i, 1, zero_cnt / 2) {
		zero.pop_back();
	}
	FOR(i, 1, one_cnt / 2) {
		one.pop_front();
	}
	zero_cnt /= 2;
	one_cnt /= 2;
	while (zero_cnt != 0 && one_cnt != 0) {
		if (zero.front() < one.front()) {
			cout << 0;
			zero.pop_front();
			zero_cnt--;
		}
		else if (zero.front() > one.front()) {
			cout << 1;
			one.pop_front();
			one_cnt--;
		}
	}
	while (zero_cnt != 0) {
		cout << 0;
		zero.pop_front();
		zero_cnt--;
	}
	while (one_cnt != 0) {
		cout << 1;
		one.pop_front();
		one_cnt--;
	}

	return 0;
}