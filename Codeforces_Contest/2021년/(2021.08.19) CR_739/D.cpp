#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<ll> v;

int main() {
	FASTIO;
	ll num = 1;
	while (num <= pow(2, 60)) {
		v.push_back(num);
		num *= 2;
	}
	int vlen = v.size();
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int mini = 100;
		FOR(i, 0, vlen - 1) {
			string s1 = to_string(v[i]);
			string s2 = to_string(N);
			int s1_len = s1.size();
			int s2_len = s2.size();
			int idx = 0;
			int cnt = 0;
			FOR(i, 0, s2_len - 1) {
				if (s2[i] == s1[idx]) {
					cnt++;
					idx++;
					if (idx >= s1_len)
						break;
				}
			}
			mini = min(mini, abs(cnt - s2_len) + abs(cnt - s1_len));
		}
		cout << mini << "\n";
	}


	return 0;
}