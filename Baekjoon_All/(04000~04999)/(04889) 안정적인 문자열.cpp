#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string s;
	int idx = 1;
	while (true) {
		cin >> s;
		int len = s.size();
		bool flag = true;
		FOR(i, 0, len - 1) {
			if (s[i] == '-') {
				flag = false;
				break;
			}
		}
		if (!flag)
			break;

		vector<int> v;
		int cnt = 0;
		FOR(i, 0, len - 1) {
			if (s[i] == '{') {
				v.push_back(1);
			}
			else if (s[i] == '}') {
				if (v.empty()) {
					cnt++;
					v.push_back(1);
				}
				else {
					v.pop_back();
				}
			}
		}
		int vlen = v.size();
		cnt += vlen / 2;

		cout << idx << ". " << cnt << "\n";
		idx++;
	}


	return 0;
}