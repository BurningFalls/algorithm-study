#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll Ch1(string s) {
	s += '.';
	int len = s.size();
	vector<int> v;
	string tmp = "";
	FOR(i, 0, len - 1) {
		if (s[i] == '.') {
			int num = stoi(tmp);
			v.push_back(num);
			tmp = "";
		}
		else
			tmp += s[i];
	}
	ll num = 1;
	ll ans = 0;
	ROF(i, 7, 0) {
		ans += num * v[i];
		num *= 256;
	}

	return ans;
}

string Ch2(ll num) {
	string ans = "";
	vector<int> v;
	while (num != 0) {
		v.push_back(num % 256);
		num /= 256;
	}
	int vlen = v.size();
	FOR(i, 1, 8 - vlen)
		v.push_back(0);
	ROF(i, 7, 0) {
		ans += to_string(v[i]);
		if (i == 0) continue;
		ans += '.';
	}
	return ans;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int M;
		cin >> M;
		if (M == 1) {
			string N;
			cin >> N;
			cout << Ch1(N);
		}
		else if (M == 2) {
			ll N;
			cin >> N;
			cout << Ch2(N);
		}
		cout << "\n";
	}


	return 0;
}